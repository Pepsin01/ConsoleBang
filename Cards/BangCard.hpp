#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int BANG_CARD_COUNT = 25;

class BangCard : public PlayableCard
{
public:
	BangCard(GameStateControllor& gameState, CardColor color);
	void execute() override;
};

