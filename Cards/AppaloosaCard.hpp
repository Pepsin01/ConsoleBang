#pragma once
#include "../CoreModul/Card.hpp"

class AppaloosaCard : public virtual BlueCard
{
	public:
		AppaloosaCard(GameStateController& gameState, CardColor color);
		static constexpr int APPALOOSA_CARD_COUNT = 1;
};

