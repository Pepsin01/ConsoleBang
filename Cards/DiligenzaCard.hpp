#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class DiligenzaCard : public PlayableCard
{
public:
	DiligenzaCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int DILIGENZA_CARD_COUNT = 2;
};

