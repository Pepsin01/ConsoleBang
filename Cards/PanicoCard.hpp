#pragma once
#include "../CoreModul/Card.hpp"

constexpr int PANICO_CARD_COUNT = 4;

class PanicoCard : public PlayableCard
{
public:
	PanicoCard(GameStateControllor& gameState, CardColor color);
	void execute() override;
};

