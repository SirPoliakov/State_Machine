#pragma once
#include "HSMBase.h"

class HierarchicalStateMachine : public HSMBase
{
protected:
	States* myStates;
	State* initialState;
	State* currentState;

public:
	HierarchicalStateMachine(State* initStateP, State* currentStateP = nullptr) : myStates(nullptr), initialState(initStateP), currentState(currentStateP) {}
	States* getStates() override;
	UpdateResult update();
	Actions* updateDown(State* stateP, Level myLvl);
};