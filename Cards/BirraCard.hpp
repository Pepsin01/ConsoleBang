#pragma once
#include "../CoreModul/Card.hpp"

constexpr int BIRRA_CARD_COUNT = 6;

class BirraCard : public PlayableCard
{
public:
	BirraCard(GameStateControllor& gameState, CardColor color);
	void execute() override;
};

