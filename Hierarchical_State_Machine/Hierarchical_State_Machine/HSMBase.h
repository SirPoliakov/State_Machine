#pragma once
#include "UpdateResult.h"

class State;
using States = std::vector<State*>;

class HSMBase
{
public:
	Action* getAction() { return new Action{}; }
	UpdateResult update() { return UpdateResult{}; }
	virtual States* getStates() = 0;

};