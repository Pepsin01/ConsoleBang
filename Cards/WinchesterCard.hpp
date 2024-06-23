#pragma once
#include "../CoreModul/Card.hpp"

class WinchesterCard : public WeaponCard
{
public:
	WinchesterCard(GameStateController& gameState, CardColor color);
	static constexpr int WINCHESTER_CARD_COUNT = 1;
};

