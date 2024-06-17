#pragma once
#include "GameUIInput.hpp"
#include "GameUIOutput.hpp"
#include "CardUIOutput.hpp"
#include "../CoreModul/GameState.hpp"
#include "../CoreModul/Player.hpp"
#include "../CoreModul/Card.hpp"
#include <iostream>
#include <string>

class CardUIInput
{
public:
	static int selectCastTarget(GameStateControllor& gameState, Card& card);
	static int selectEquipmentCard(Player& player);
	static bool fromHandOrEquipment();
};

