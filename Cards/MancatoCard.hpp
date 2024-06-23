#pragma once
#include "../CoreModul/Card.hpp"

class MancatoCard : public ReactionCard
{
public:
	MancatoCard(GameStateController& gameState, CardColor color);
	static constexpr int MANCATO_CARD_COUNT = 12;
};

