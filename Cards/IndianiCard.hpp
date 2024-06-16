#pragma once
#include "../CoreModul/Card.hpp"

constexpr int INDIANI_CARD_COUNT = 2;

class IndianiCard : public PlayableCard
{
public:
	IndianiCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

