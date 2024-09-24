#pragma once
#include "Action.h"

class Transition;

using Actions = std::vector<Action*>;
using Level = int;

struct UpdateResult
{
	Actions actions;
	Transition* trans;
	Level lvl;

	void operator+=(Action* myAction);
	void operator+=(Actions* myActions);
};