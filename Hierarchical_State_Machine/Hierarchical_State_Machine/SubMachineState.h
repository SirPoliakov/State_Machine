#pragma once
#include "State.h"

class SubMachineState : public State, public HierarchicalStateMachine
{

public:
	SubMachineState(State* initStateP,
					Action* stateA,
					Action* entryA,
					Action* exitA,
					std::vector<Transition*> transitionsP,
					HierarchicalStateMachine* parentP, 
					State* optionalCurrentStateP = nullptr) : State(stateA,entryA,exitA,transitionsP, parent),
															  HierarchicalStateMachine(initStateP, optionalCurrentStateP)
	{}

	Action* getAction() { return State::getAction(); }
	UpdateResult update() { return HierarchicalStateMachine::update(); }
	States* getStates()
	{
		if (currentState)
		{
			States* res = new States{ this };
			res->insert(res->begin(),
				currentState->getStates()->begin(),
				currentState->getStates()->end()
			);
			return res;
		}
		else return new States{ this };
	}
};