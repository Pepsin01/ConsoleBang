#pragma once
#include "../CoreModul/Card.hpp"

constexpr int GATLING_CARD_COUNT = 1;

class GatlingCard : public PlayableCard
{
public:
	GatlingCard(GameStateControllor& gameState, CardColor color);
	void execute() override;
};

