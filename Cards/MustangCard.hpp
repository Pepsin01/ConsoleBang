#pragma once
#include "../CoreModul/Card.hpp"

constexpr int MUSTANG_CARD_COUNT = 2;

class MustangCard : public BlueCard
{
public:
	MustangCard(GameStateControllor& gameState, CardColor color);
};

