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

bool Player::isDead() const
{
	return health <= 0;
}

void Player::playCard(int cardIndex)
{
	if (BlueCard* blueCard = dynamic_cast<BlueCard*>(hand[cardIndex].get()))
	{
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(hand[cardIndex].get()))
			replaceWeapon(move(hand[cardIndex]));
		else if (DebuffCard* debuff = dynamic_cast<DebuffCard*>(hand[cardIndex].get()))
		{
			auto result = gameState.castDebuff(move(hand[cardIndex])); // cast the debuff
			hand.erase(hand.begin() + cardIndex); // remove the card from the player's hand

			// if the debuff was not casted, return the card to the player's hand
			if (!result)
				receiveCard(move(hand[cardIndex])); // return the card to the player's hand
		}
		else
			moveCardToEquipment(move(hand[cardIndex]));
	}
	else if (PlayableCard* playableCard = dynamic_cast<PlayableCard*>(hand[cardIndex].get()))
	{

	}
	else
		PlayerUIOutput::cannotPlayCardScreen(*hand[cardIndex]);
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
	if (!passesTurn())
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
}

void Player::showPrivateProfile()
{
	PlayerUIOutput::playerPrivateScreen(
		this->gameState.getCurrentPlayerIndex(),
		roleToString(), this->health,
		this->role == PlayerRole::SHERIF ? 5 : 4,
		this->hand, this->equipment
	);
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

bool Player::passesTurn()
{
	if (isDead())
	{
		PlayerUIOutput::playerDeadScreen();
		return true;
	}
	if (!evaluatePrigione())
	{
		PlayerUIOutput::playerJailScreen();
		return true;
	}
	return false;
}

bool Player::evaluatePrigione()
{
	for (size_t i = 0; i < equipment.size(); i++)
		if (typeid(equipment[i]) == typeid(PrigioneCard))
		{
			gameState.discardCard(move(equipment[i]));
			equipment.erase(equipment.begin() + i);
			unique_ptr<Card> card = gameState.drawCard();
			if (card->color == CardColor::HEARTS)
			{
				gameState.discardCard(move(card));
				return true;
			}
			else
			{
				gameState.discardCard(move(card));
				return false;
			}
		}
	return true;
}

std::string Player::roleToString() const
{
	switch (this->role)
	{
	case SHERIF:
		return "Sherif";
	case VICE:
		return "Vice";
	case BANDIT:
		return "Bandit";
	case RENEGADE:
		return "Renegade";
	}
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

void Player::receiveDebuff(std::unique_ptr<Card> card)
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		if (typeid(card) == typeid(equipment[i]))
		{
			gameState.discardCard(move(equipment[i]));
			equipment.erase(equipment.begin() + i);
			equipment.push_back(move(card));
			return;
		}
	}
	equipment.push_back(move(card));
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
	if (isDead())
		role = roleToString();
	else
	{
		if (this->role == PlayerRole::SHERIF)
			role = "Sherif";
		else
			role = "Unknown";
	}

	PlayerUIOutput::playerPublicScreen(role, this->health, this->role == PlayerRole::SHERIF ? 5 : 4, this->equipment);
}
