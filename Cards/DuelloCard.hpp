#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class DuelloCard : public PlayableCard
{
public:
	DuelloCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int DUELLO_CARD_COUNT = 3;
};

