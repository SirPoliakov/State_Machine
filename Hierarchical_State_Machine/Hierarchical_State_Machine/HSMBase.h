#pragma once
#include "UpdateResult.h"

class State;
using States = std::vector<State*>;

class HSMBase
{
public:
	//virtual Action* getAction() { return new Action{}; }
	virtual UpdateResult update() { return UpdateResult{}; }
	virtual States* getStates() = 0;

};