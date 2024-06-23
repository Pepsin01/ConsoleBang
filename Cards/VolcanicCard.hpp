#pragma once
#include "../CoreModul/Card.hpp"

class VolcanicCard : public WeaponCard
{
public:
	VolcanicCard(GameStateController& gameState, CardColor color);
	static constexpr int VOLCANIC_CARD_COUNT = 2;
};

