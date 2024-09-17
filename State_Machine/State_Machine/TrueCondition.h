#pragma once
#include "Condition.h"
class TrueCondition : public Condition
{
public:
	bool test() override
	{
		return true;
	}
};