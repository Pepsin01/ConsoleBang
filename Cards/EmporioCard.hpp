#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int EMPORIO_CARD_COUNT = 2;

class EmporioCard : public PlayableCard
{
public:
	EmporioCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
};

