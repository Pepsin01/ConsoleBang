#include "Player.hpp"
using namespace std;

int Player::calculateRange() const
{
	int range = 0;
	for (size_t i = 0; i < equipment.size(); i++)
	{
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(equipment[i].get()))
		{
			range += weapon->range;
		}
		if (typeid(*equipment[i]) == typeid(AppaloosaCard))
		{
			range++;
		}
	}
	return range == 0 ? 1 : range;
}

int Player::getHandSize() const
{
	return hand.size();
}

GameStateControllor& Player::getGameState() const
{
	return gameState;
}

void Player::playCard(int cardIndex)
{
	if (BlueCard* blueCard = dynamic_cast<BlueCard*>(hand[cardIndex].get()))
	{
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(hand[cardIndex].get()))
			replaceWeapon(move(hand[cardIndex]));
		else if (PrigioneCard* prigione = dynamic_cast<PrigioneCard*>(hand[cardIndex].get()))
		{

		}
		else
			moveCardToEquipment(move(hand[cardIndex]));
	}
	GameUIInput::waitForEnter();
}



Player::Player(GameStateControllor& gameState, PlayerRole role) : role(role), gameState(gameState)
{
	if (role == SHERIF)
		health = 5;
	else
		health = 4;

	for (size_t i = 0; i < health; i++)
	{
		hand.push_back(gameState.drawCard());
	}
	int r = calculateRange();
}

void Player::takeTurn()
{
	// at the beginning of the turn, player draws two cards
	this->receiveCard(gameState.drawCard());
	this->receiveCard(gameState.drawCard());

	this->showPrivateProfile();

	// player's turn loop
	while (!PlayerUIInput::parseCommand(*this))
	{
		this->showPrivateProfile();
	}
}

void Player::showPrivateProfile()
{
	string role;
	switch (this->role)
	{
		case SHERIF:
			role = "Sherif";
			break;
		case VICE:
			role = "Vice";
			break;
		case BANDIT:
			role = "Bandit";
			break;
		case RENEGADE:
			role = "Renegade";
			break;
	}

	PlayerUIOutput::playerPrivateScreen(this->gameState.getCurrentPlayerIndex(), role, this->health, this->role == PlayerRole::SHERIF ? 5 : 4, this->hand, this->equipment);
}

void Player::moveCardToEquipment(std::unique_ptr<Card> card)
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		if(typeid(card) == typeid(equipment[i]))
		{
			gameState.discardCard(move(equipment[i]));
			equipment.erase(equipment.begin() + i);
			equipment.push_back(move(card));
			return;
		}
	}
	equipment.push_back(move(card));
}

void Player::replaceWeapon(std::unique_ptr<Card> card)
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(equipment[i].get()))
		{
			gameState.discardCard(move(equipment[i]));
			equipment.erase(equipment.begin() + i);
			equipment.push_back(move(card));
			return;
		}
	}
	equipment.push_back(move(card));
}

int Player::getHealth() const
{
	return health;
}

void Player::takeDamage(int damage)
{
	health -= damage;
}

unique_ptr<Card> Player::handRandomCard()
{
	shuffle(hand.begin(), hand.end(), default_random_engine{ static_cast<unsigned int>(time(nullptr)) });
	unique_ptr<Card> card = move(hand.back());
	hand.pop_back();
	return card;
}

unique_ptr<Card> Player::handEquipmentCard(int index)
{
	unique_ptr<Card> card = move(hand[index]);
	hand.erase(hand.begin() + index);
	return card;
}

void Player::receiveCard(std::unique_ptr<Card> card)
{
	hand.push_back(move(card));
}

void Player::discardCard(int index)
{
	unique_ptr<Card> card = move(hand[index]);
	hand.erase(hand.begin() + index);
	gameState.discardCard(move(card));
}

void Player::showPublicProfile()
{
	string role;
	if (this->role == PlayerRole::SHERIF)
		role = "Sherif";
	else
		role = "Unknown";

	PlayerUIOutput::playerPublicScreen(role, this->health, this->role == PlayerRole::SHERIF ? 5 : 4, this->equipment);
}
