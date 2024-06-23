#pragma once
#include "../CoreModul/Card.hpp"

class MustangCard : public BlueCard
{
public:
	MustangCard(GameStateController& gameState, CardColor color);
	static constexpr int MUSTANG_CARD_COUNT = 2;
};

