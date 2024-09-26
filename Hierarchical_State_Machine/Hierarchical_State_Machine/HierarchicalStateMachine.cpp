#include "HierarchicalStateMachine.h"
#include "State.h"
#include "Transition.h"

States* HierarchicalStateMachine::getStates()
{
    if (currentState) return currentState->getStates();
    else return new States{};
}


UpdateResult HierarchicalStateMachine::update()
{
	UpdateResult result;

	if (!currentState)
	{
		currentState = initialState;
		result += currentState->getEntryAction();
	}

	Transition* triggeredTransition = nullptr;

	for (Transition* transP : currentState->getTransitions())
	{
		if (transP->isTriggered())
		{
			triggeredTransition = transP;
			break;
		}
	}

	if (triggeredTransition)
	{
		result.trans = triggeredTransition;
		result.lvl = triggeredTransition->getLevel();
	}
	else
	{
		result = currentState->update();
	}

	if (result.trans)
	{
		State* targetState = nullptr;

		if (result.lvl == 0)
		{
			targetState = result.trans->getTargetState();
			result += currentState->getExitAction();
			result += result.trans->getAction();
			result += targetState->getEntryAction();

			currentState = targetState;

			result += getAction();

			result.trans = nullptr;
		}
		else if (result.lvl > 0)
		{
			result += currentState->getExitAction();
			currentState = nullptr;
			result.lvl -= 1;
		}
		else
		{
			targetState = result.trans->getTargetState();
			HierarchicalStateMachine* targetMachine = targetState->getParent();
			result += targetMachine->updateDown(targetState, -result.lvl, result.trans);
			result.trans = nullptr;
		}
	}
	else
	{
		result += getAction();
	}

	return result;
}



Actions* HierarchicalStateMachine::updateDown(State* stateP, Level myLvl, Transition* transP)
{
    Actions* returnedActions = new Actions{};
	
    if (myLvl > 0)
    {
        returnedActions = getParent()->updateDown(this->getSelfState(), myLvl - 1, transP);
		
    }
    
    if (currentState)
    {
        returnedActions->push_back(currentState->getExitAction());
		int it = 0;
		if (search(transP->getAction(), *returnedActions, it))
		{
			auto ite = returnedActions->begin() + it;
			returnedActions->erase(ite);
			returnedActions->push_back(transP->getAction());
		}
		else
		{
			returnedActions->push_back(transP->getAction());
		}
    }

	currentState = stateP;
    returnedActions->push_back(stateP->getEntryAction());

    return returnedActions;
}

Action* HierarchicalStateMachine::getAction()
{
    if (currentState) return currentState->getAction();
    else return initialState->getAction();
}

bool HierarchicalStateMachine::search(Action* val, Actions myActions, int& it)
{
	bool res = false;
	for (Action* act : myActions)
	{
		if (act == val)
		{
			res = true;
			break;
		}
		it++;
	}
	return res;
}
