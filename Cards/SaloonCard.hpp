#pragma once
#include "../CoreModul/Card.hpp"

constexpr int SALOON_CARD_COUNT = 1;

class SaloonCard : public PlayableCard
{
public:
	SaloonCard(GameStateControllor& gameState, CardColor color);
	void execute();
};

