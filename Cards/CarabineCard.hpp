#pragma once
#include "../CoreModul/Card.hpp"

constexpr int CARABINE_CARD_COUNT = 1;

class CarabineCard : public WeaponCard
{
public:
	CarabineCard(GameStateControllor& gameState, CardColor color);
};

