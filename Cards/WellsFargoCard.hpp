#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class WellsFargoCard : public PlayableCard
{
public:
	WellsFargoCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int WELLS_FARGO_CARD_COUNT = 1;
};

