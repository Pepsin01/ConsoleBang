#pragma once
#include "../CoreModul/Card.hpp"

class PrigioneCard : public DebuffCard
{
public:
	PrigioneCard(GameStateController& gameState, CardColor color);
	static constexpr int PRIGIONE_CARD_COUNT = 3;
};

