#pragma once
#include "Condition.h"

class EscapedCondition : public Condition
{
private:
	const int distance;

public:
	EscapedCondition(const int& dist): distance(dist)
	{}

	bool test() override
	{
		return distance > 15;
	}
};