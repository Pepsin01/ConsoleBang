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

void Player::playCard(GameStateControllor& gameState, int cardIndex)
{
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
	this->showPrivateProfile();

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

void Player::showPublicProfile()
{
	string role;
	if (this->role == PlayerRole::SHERIF)
		role = "Sherif";
	else
		role = "Unknown";

	PlayerUIOutput::playerPublicScreen(role, this->health, this->role == PlayerRole::SHERIF ? 5 : 4, this->equipment);
}
