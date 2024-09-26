#include "UpdateResult.h"

void UpdateResult::operator+=(Action* myAction)
{
	actions.push_back(myAction);
}

void UpdateResult::operator+=(Actions* myActions)
{
	for (auto action : *myActions)
	{
		actions.push_back(action);
	}
}

void UpdateResult::operator=(UpdateResult res)
{
	trans = res.trans;
	lvl = res.lvl;
	
	this->operator+=(&res.actions);
}
