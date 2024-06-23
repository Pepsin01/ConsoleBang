#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int INDIANI_CARD_COUNT = 2;

class IndianiCard : public PlayableCard
{
public:
	IndianiCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
};

