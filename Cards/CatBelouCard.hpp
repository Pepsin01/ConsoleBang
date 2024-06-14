#pragma once
#include "../CoreModul/Card.hpp"

constexpr int CATBELOU_CARD_COUNT = 4;

class CatBelouCard : public PlayableCard
{
public:
	CatBelouCard(GameStateControllor& gameState, CardColor color);
	void execute() override;
};

