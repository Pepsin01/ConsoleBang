#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int GATLING_CARD_COUNT = 1;

class GatlingCard : public PlayableCard
{
public:
	GatlingCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

