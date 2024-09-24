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
