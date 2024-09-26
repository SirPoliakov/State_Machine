#pragma once
#include "HSMBase.h"

class HierarchicalStateMachine : public HSMBase
{
protected:
	States* myStates;
	State* initialState;
	State* currentState;
	State* selfState = nullptr;
	HierarchicalStateMachine* parent = nullptr;

	void selfStateChoice(State* choiceP) { selfState = choiceP; }

public:
	HierarchicalStateMachine(State* initStateP, State* currentStateP = nullptr) : myStates(nullptr), initialState(initStateP), currentState(currentStateP) {}
	
	State* getSelfState() { return selfState; }
	void addParent(HierarchicalStateMachine* parentP) { parent = parentP; }
	HierarchicalStateMachine* getParent() { return parent; }

	States* getStates() override;
	UpdateResult update() override;
	Actions* updateDown(State* stateP, Level myLvl, Transition* transP);
	Action* getAction();

	bool search(Action* val, Actions myAct, int& it);
};