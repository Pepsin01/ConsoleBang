#pragma once
#include "../CoreModul/Card.hpp"

class CarabineCard : public WeaponCard
{
public:
	CarabineCard(GameStateController& gameState, CardColor color);
	static constexpr int CARABINE_CARD_COUNT = 1;
};

