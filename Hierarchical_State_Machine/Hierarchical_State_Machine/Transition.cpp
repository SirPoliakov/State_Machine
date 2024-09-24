#include "Transition.h"
#include "State.h"
#include "Condition.h"

bool Transition::isTriggered() const
{
    return cond->test();
}

State* Transition::getTargetState() const
{
	return targetedState;
}

Action* Transition::getAction()
{
	return action;
}

