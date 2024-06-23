#pragma once
#include "../CoreModul/Card.hpp"

class BarileCard : public BlueCard
{
public:
	BarileCard(GameStateController& gameState, CardColor color);
	static constexpr int BARILE_CARD_COUNT = 2;
};

