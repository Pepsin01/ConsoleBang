#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class PanicoCard : public PlayableCard
{
public:
	PanicoCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int PANICO_CARD_COUNT = 4;
};

