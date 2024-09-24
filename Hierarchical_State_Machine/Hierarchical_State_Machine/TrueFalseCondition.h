#pragma once
#include "Condition.h"

class TrueCondition : public Condition
{
	bool test() override { return true; }
};

class FalseCondition : public Condition
{
	bool test() override { return false; }
};