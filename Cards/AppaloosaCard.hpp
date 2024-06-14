#pragma once
#include "../CoreModul/Card.hpp"

constexpr int APPALOOSA_CARD_COUNT = 1;

class AppaloosaCard : public virtual BlueCard
{
	public:
		AppaloosaCard(GameStateControllor& gameState, CardColor color);
};

