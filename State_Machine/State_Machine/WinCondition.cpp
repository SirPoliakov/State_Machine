#include "WinCondition.h"
#include<cstdlib>
#include <iostream>

bool WinCondition::test()
{
	srand((unsigned)time(NULL));
	int random = rand();
	random = random % 2;

	if (random == 1) return true;
	else return false;
}
