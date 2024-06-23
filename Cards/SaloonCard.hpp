#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class SaloonCard : public PlayableCard
{
public:
	SaloonCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int SALOON_CARD_COUNT = 1;
};

