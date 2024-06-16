#pragma once
#include <iostream>
#include <string>
#include "../CoreModul/Player.hpp"
#include "GameUIOutput.hpp"
#include "GameUIInput.hpp"

class PlayerUIInput
{
public:
	static bool parseCommand(Player& player);
};

