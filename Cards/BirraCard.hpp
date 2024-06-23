#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class BirraCard : public PlayableCard
{
public:
	BirraCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int BIRRA_CARD_COUNT = 6;
};

