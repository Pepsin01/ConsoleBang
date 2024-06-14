#pragma once
#include "../CoreModul/Card.hpp"

constexpr int MANCATO_CARD_COUNT = 12;

class MancatoCard : public ReactionCard
{
public:
	MancatoCard(GameStateControllor& gameState, CardColor color);
};

