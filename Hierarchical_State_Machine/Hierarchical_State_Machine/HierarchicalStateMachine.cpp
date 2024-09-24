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
    if (!currentState)
    {
        currentState = initialState;
        UpdateResult result;
        result += currentState->getEntryAction();

        return result;
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

    UpdateResult result;

    if (!triggeredTransition)
    {
        result = currentState->update();
        result += getAction();
    }
    else
    {
        result.trans = triggeredTransition;
        result.lvl = triggeredTransition->getLevel();

        State* targetState;

        if (result.lvl == 0)
        {
            targetState = result.trans->getTargetState();
            result += currentState->getExitAction();
            result += currentState->getAction();
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
            result += targetMachine->updateDown(targetState, -result.lvl);
            result.trans = nullptr;
        }
    }
    return result;
}



Actions* HierarchicalStateMachine::updateDown(State* stateP, Level myLvl)
{
    Actions* returnedActions = new Actions{};

    if (myLvl > 0)
    {
        returnedActions = updateDown(stateP, myLvl - 1);
    }
    
    if (currentState)
    {
        returnedActions->push_back(currentState->getExitAction());
        currentState = stateP;
        returnedActions->push_back(stateP->getEntryAction());
    }

    return returnedActions;
}
