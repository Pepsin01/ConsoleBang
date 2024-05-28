#pragma once
#include "ICard.hpp"
#include "Player.hpp"

class BangCard : public ICard
{
	// Inherited via ICard
	void execute(GameStateControllor& gameState, Player& currentPlayer) override;
};

