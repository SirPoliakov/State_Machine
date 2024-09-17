#pragma once

#include "Action.h"

class State;
class Condition;

class Transition
{
private:
	State* targetedState;
	Condition* cond;
	Action action;

public:
	Transition(const Action& actionP, Condition* conditionP) :
		action(actionP), targetedState(nullptr), cond(conditionP)
	{}

	void setTargetedState(State* targetedStateP) { targetedState = targetedStateP; }

	bool isTriggered() const;
	State* getTargetState() const;
	Action getAction() const;
};