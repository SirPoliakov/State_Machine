#pragma once
#include "Transition.h"

class State
{
private:
	Action action;
	Action entryAction;
	Action exitAction;
	std::vector<Transition*> trans;

public:
	State(const Action& stateA, const Action& entryA, const Action& exitA, std::vector<Transition*> transitionsP):
		action(stateA), entryAction(entryA), exitAction(exitA), trans(transitionsP)
	{}

	Action getAction() const { return action; }
	Action getEntryAction() const { return entryAction; }
	Action getExitAction() const { return exitAction; }
	std::vector<Transition*> getTransitions() const{ return trans; }
};