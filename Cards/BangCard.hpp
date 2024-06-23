#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int BANG_CARD_COUNT = 25;

class BangCard : public PlayableCard
{
public:
	BangCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
};

