#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

constexpr int DILIGENZA_CARD_COUNT = 2;

class DiligenzaCard : public PlayableCard
{
public:
	DiligenzaCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
};

