#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class BangCard : public PlayableCard
{
public:
	BangCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int BANG_CARD_COUNT = 25;
};

