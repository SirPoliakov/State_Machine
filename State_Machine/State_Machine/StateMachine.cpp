#include "StateMachine.h"

StateMachine::StateMachine(State* myState) : currentState(myState)
{
}

std::vector<Action> StateMachine::update()
{
    Transition* triggeredTransition = nullptr;

    for (Transition* trans : currentState->getTransitions())
    {
        if (trans->isTriggered())
        {
            triggeredTransition = trans;
            break;
        }
    }

    if (triggeredTransition != nullptr)
    {
        std::vector<Action> returnedActions{ 
            currentState->getAction(),
            triggeredTransition->getAction(),
            currentState->getExitAction(),
            triggeredTransition->getTargetState()->getEntryAction()
        };

        currentState = triggeredTransition->getTargetState();
        return returnedActions;
    }
    else
    {
        return std::vector<Action>{ currentState->getAction()};
    }
}
