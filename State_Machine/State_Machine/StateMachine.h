#pragma once
#include "State.h"

class StateMachine
{
private:
	std::vector<State> states;
	State* currentState;

public:
	StateMachine(State* myStates);
	std::vector<Action> update();
};