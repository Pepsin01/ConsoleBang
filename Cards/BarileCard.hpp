#pragma once
#include "../CoreModul/Card.hpp"

constexpr int BARILE_CARD_COUNT = 2;

class BarileCard : public BlueCard
{
public:
	BarileCard(GameStateControllor& gameState, CardColor color);
};

