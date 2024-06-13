#pragma once
#include "Card.hpp"
#include "Player.hpp"

class BangCard : public Card
{
	// Inherited via ICard
	void execute(GameStateControllor& gameState, Player& currentPlayer);
};

