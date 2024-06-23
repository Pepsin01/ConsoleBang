#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int BIRRA_CARD_COUNT = 6;

class BirraCard : public PlayableCard
{
public:
	BirraCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
};

