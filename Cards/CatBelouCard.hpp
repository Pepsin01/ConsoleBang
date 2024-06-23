#pragma once
#include "../CoreModul/Card.hpp"
#include "../CoreModul/Player.hpp"

class CatBelouCard : public PlayableCard
{
public:
	CatBelouCard(GameStateController& gameState, CardColor color);
	bool execute(Player& player) override;
	static constexpr int CATBELOU_CARD_COUNT = 4;
};

