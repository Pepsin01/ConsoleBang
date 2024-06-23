#pragma once
#include "../CoreModul/Card.hpp"

constexpr int SCHOFIELD_CARD_COUNT = 3;

class SchofieldCard : public WeaponCard
{
public:
	SchofieldCard(GameStateController& gameState, CardColor color);
};

