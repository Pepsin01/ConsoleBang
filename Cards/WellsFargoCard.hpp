#pragma once
#include "../CoreModul/Card.hpp"

constexpr int WELLS_FARGO_CARD_COUNT = 1;

class WellsFargoCard : public PlayableCard
{
public:
	WellsFargoCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

