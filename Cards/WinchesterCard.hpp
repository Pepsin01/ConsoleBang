#pragma once
#include "../CoreModul/Card.hpp"

constexpr int WINCHESTER_CARD_COUNT = 1;

class WinchesterCard : public WeaponCard
{
public:
	WinchesterCard(GameStateControllor& gameState, CardColor color);
};

