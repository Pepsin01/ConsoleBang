#pragma once
#include <string>
#include <memory>

class GameStateControllor;  // Forward declaration
class Player;  // Forward declaration

enum CardColor
{
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES
};

class Card {
private:
	GameStateControllor& gameState;
public:
	const std::string name;
	const std::string description;
	const CardColor color;
};

class PlayableCard : public Card {
public:
	virtual void execute() = 0;
};

class ReactionCard : public Card {
public:

};

class BlueCard : public Card {
public:

};

class WeaponCard : public BlueCard {
public:
	int range;
};