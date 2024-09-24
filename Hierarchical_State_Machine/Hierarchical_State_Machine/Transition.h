#pragma once
#include "HSMBase.h"

class Condition;

class Transition
{
private:
	State* targetedState;
	Condition* cond;
	Action* action;
	Level lvlDiff;

public:
	Transition(Action* actionP, Condition* conditionP, Level lvlD) :
		action(actionP), targetedState(nullptr), cond(conditionP), lvlDiff(lvlD)
	{}
	Transition(): targetedState(nullptr), cond(nullptr), action(new Action()), lvlDiff(0) {}

	void setTargetedState(State* targetedStateP) { targetedState = targetedStateP; }

	Level getLevel() { return lvlDiff; }
	bool isTriggered() const;
	State* getTargetState() const;
	Action* getAction();
};