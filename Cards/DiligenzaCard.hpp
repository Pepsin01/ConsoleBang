#pragma once
#include "../CoreModul/Card.hpp"

constexpr int DILIGENZA_CARD_COUNT = 2;

class DiligenzaCard : public PlayableCard
{
public:
	DiligenzaCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

