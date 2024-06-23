#pragma once
#include "../CoreModul/Card.hpp"

class SchofieldCard : public WeaponCard
{
public:
	SchofieldCard(GameStateController& gameState, CardColor color);
	static constexpr int SCHOFIELD_CARD_COUNT = 3;
};

