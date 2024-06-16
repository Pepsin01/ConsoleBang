#pragma once
#include "../CoreModul/Card.hpp"

constexpr int DUELLO_CARD_COUNT = 3;

class DuelloCard : public PlayableCard
{
public:
	DuelloCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

