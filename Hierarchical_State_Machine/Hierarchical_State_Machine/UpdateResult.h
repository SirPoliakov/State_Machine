#pragma once
#include "Action.h"

class Transition;

using Actions = std::vector<Action*>;
using Level = int;

struct UpdateResult
{
	Actions actions = Actions{};
	Transition* trans = nullptr;
	Level lvl = 0;

	void operator+=(Action* myAction);
	void operator+=(Actions* myActions);
	void operator=(UpdateResult res);

	void clear() { actions.clear(); trans = nullptr; lvl = 0; }

};