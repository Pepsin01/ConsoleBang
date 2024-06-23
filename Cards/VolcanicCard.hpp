#pragma once
#include "../CoreModul/Card.hpp"

constexpr int VOLCANIC_CARD_COUNT = 2;

class VolcanicCard : public WeaponCard
{
public:
	VolcanicCard(GameStateController& gameState, CardColor color);
};

