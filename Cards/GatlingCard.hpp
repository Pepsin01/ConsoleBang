#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class GatlingCard : public PlayableCard
{
public:
	GatlingCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int GATLING_CARD_COUNT = 1;
};

