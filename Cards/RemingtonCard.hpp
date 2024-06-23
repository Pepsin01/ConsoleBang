#pragma once
#include "../CoreModul/Card.hpp"

class RemingtonCard : public WeaponCard
{
public:
	RemingtonCard(GameStateController& gameState, CardColor color);
	static constexpr int REMINGTON_CARD_COUNT = 1;
};

