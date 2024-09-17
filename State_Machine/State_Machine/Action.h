#pragma once
#include <string>
#include <vector>
#include <iostream>

class Action
{
public:
	Action(std::string actionN) : actionName(actionN) {}
	std::string getName() { return actionName; }

	void proceedAction();

private:
	std::string actionName;
};