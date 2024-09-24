#pragma once
#include "HierarchicalStateMachine.h"

class State : public HSMBase
{
protected:
	Action* action;
	Action* entryAction;
	Action* exitAction;
	std::vector<Transition*> trans;
	HierarchicalStateMachine* parent;

public:
	State(Action* stateA, Action* entryA, Action* exitA, std::vector<Transition*> transitionsP, HierarchicalStateMachine* parentP):
		action(stateA), entryAction(entryA), exitAction(exitA), trans(transitionsP), parent(parentP)
	{}

	States* getStates() override { return new States{ this }; }
	HierarchicalStateMachine* getParent () { return parent; }

	void addParent(HierarchicalStateMachine* parentP) { parent = parentP; }

	Action* getAction() { return action; }
	Action* getEntryAction() { return entryAction; }
	Action* getExitAction() { return exitAction; }
	std::vector<Transition*> getTransitions() const{ return trans; }
};