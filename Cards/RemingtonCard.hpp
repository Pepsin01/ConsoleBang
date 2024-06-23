#pragma once
#include "../CoreModul/Card.hpp"

constexpr int REMINGTON_CARD_COUNT = 1;

class RemingtonCard : public WeaponCard
{
public:
	RemingtonCard(GameStateController& gameState, CardColor color);
};

