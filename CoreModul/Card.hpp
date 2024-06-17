#pragma once

//#include "GameState.hpp"
//#include "Player.hpp"

#include <string>
#include <memory>

class GameStateControllor;  // Forward declaration
class Player;  // Forward declaration

/*
* @brief Enum that represents the color of the card
*/
enum CardColor
{
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES
};

/*
* @brief Class that represents a card in the game
*/
class Card {
protected:
	GameStateControllor& gameState;

	Card(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description,
		CardColor color
	) : gameState(gameState), name(name), description(description), color(color) {}
public:
	const std::string name;
	const std::string description;
	const CardColor color;

	virtual ~Card() = default;
};

/*
* @brief Class that represents a card that can be played

*/
class PlayableCard : public Card {
protected:
	PlayableCard(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description,
		CardColor color
	) : Card(gameState, name, description, color) {}
public:
	virtual bool execute(Player& player) = 0;

	virtual ~PlayableCard() = default;
};

/*
* @brief Class that represents a card that can be used only as a reaction
*/
class ReactionCard : public Card {
protected:
	ReactionCard(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description,
		CardColor color
	) : Card(gameState, name, description, color) {}
public:
	virtual ~ReactionCard() = default;
};

/*
* @brief Class that represents a card that can be put into the equipment
*/
class BlueCard : public Card {
protected:
	BlueCard(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description, 
		CardColor color
	) : Card(gameState, name, description, color) {}
public:
	virtual ~BlueCard() = default;
};

/*
* @brief Class that represents a card that can be put into the equipment and has a debuff effect
*/
class DebuffCard : public BlueCard {
protected:
	DebuffCard(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description,
		CardColor color
	) : BlueCard(gameState, name, description, color) {}
public:
	virtual ~DebuffCard() = default;
};

/*
* @brief Class that represents a card that can be put into the equipment and has a effect on the range of the player
*/
class WeaponCard : public BlueCard {
protected:
	WeaponCard(
		GameStateControllor& gameState,
		const std::string name,
		const std::string description,
		CardColor color,
		int range
	) : BlueCard(gameState, name, description, color), range(range) {}
public:
	const int range;
	virtual ~WeaponCard() = default;
};