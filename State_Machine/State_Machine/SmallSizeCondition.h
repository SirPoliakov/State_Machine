#pragma once
#include "Condition.h"

class SmallSizeCondition : public Condition
{
private:
	// how tall the guy is in meters
	const float size;

public:
	SmallSizeCondition(const float& s): size(s) {}

	bool test() override
	{
		return size <= 1.75;
	}
};