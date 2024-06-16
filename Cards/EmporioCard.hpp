#pragma once
#include "../CoreModul/Card.hpp"

constexpr int EMPORIO_CARD_COUNT = 2;

class EmporioCard : public PlayableCard
{
public:
	EmporioCard(GameStateControllor& gameState, CardColor color);
	bool execute(Player& player) override;
};

