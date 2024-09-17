#pragma once
#include "Condition.h"

class WinCondition : public Condition
{
public:
	bool test() override;
};