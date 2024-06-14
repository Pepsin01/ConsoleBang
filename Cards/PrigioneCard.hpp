#pragma once
#include "../CoreModul/Card.hpp"

constexpr int PRIGIONE_CARD_COUNT = 3;

class PrigioneCard : public BlueCard
{
public:
	PrigioneCard(GameStateControllor& gameState, CardColor color);
};

