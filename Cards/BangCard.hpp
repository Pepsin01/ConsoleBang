#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class BangCard : public Card
{
	// Inherited via ICard
	void execute(GameStateControllor& gameState, Player& currentPlayer);
};

