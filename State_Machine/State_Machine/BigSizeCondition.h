#pragma once
#include "Condition.h"

class BigSizeCondition : public Condition
{
private:
	// how tall the guy is in meters
	const float size;

public:
	BigSizeCondition(const float& s) : size(s) {}

	bool test() override
	{
		return size >= 1.75;
	}
};