#include "Player.hpp"
using namespace std;

int Player::calculateRange() const
{
	int range = 0;
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// check if there is a weapon card in the equipment
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(equipment[i].get()))
		{
			range += weapon->range;
		}
		// check if there is an appaloosa card in the equipment
		if (typeid(*equipment[i]) == typeid(AppaloosaCard))
		{
			range++;
		}
	}
	return range == 0 ? 1 : range; // if the player has no weapon, the range is 1
}

int Player::calculateRangeWithoutWeapon() const
{
	int range = 0;
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// check if there is an appaloosa card in the equipment
		if (typeid(*equipment[i]) == typeid(AppaloosaCard))
		{
			range++;
		}
	}
	return range == 0 ? 1 : range; // if the player has no weapon, the range is 1
}

int Player::calculateDistanceModifier() const
{
	int distance = 0;
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// check if there is a mustang card in the equipment
		if (typeid(*equipment[i]) == typeid(MustangCard))
		{
			distance++;
		}
	}
	return distance;
}

int Player::getHandSize() const
{
	return hand.size();
}

int Player::getEquipmentSize() const
{
	return equipment.size();
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
	// if the card is a blue card
	if (BlueCard* blueCard = dynamic_cast<BlueCard*>(hand[cardIndex].get()))
	{
		// if the card is a weapon card
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(hand[cardIndex].get())) {
			replaceWeapon(move(hand[cardIndex]));
			hand.erase(hand.begin() + cardIndex); // remove the card from the player's hand
		}
		// if the card is a debuff card
		else if (DebuffCard* debuff = dynamic_cast<DebuffCard*>(hand[cardIndex].get()))
		{
			auto result = gameState.castDebuff(move(hand[cardIndex])); // cast the debuff
			hand.erase(hand.begin() + cardIndex); // remove the card from the player's hand

			// if the debuff was not casted, return the card to the player's hand
			if (result)
				receiveCard(move(hand[cardIndex])); // return the card to the player's hand
		}
		else
		{
			moveCardToEquipment(move(hand[cardIndex]));
			hand.erase(hand.begin() + cardIndex); // remove the card from the player's hand
		}
	}
	// if the card is a playable card
	else if (PlayableCard* playableCard = dynamic_cast<PlayableCard*>(hand[cardIndex].get()))
	{
		if (playableCard->execute(*this)) // try to execute the card
		{
			gameState.discardCard(move(hand[cardIndex])); // discard the card
			hand.erase(hand.begin() + cardIndex); // remove the card from the player's hand
		}
	}
	else
		PlayerUIOutput::cannotPlayCardScreen(*hand[cardIndex]);
}

Player::Player(GameStateControllor& gameState, PlayerRole role) : role(role), gameState(gameState)
{
	// initialize the player's health
	if (role == SHERIF)
		health = 5;
	else
		health = 4;

	// draw as many cards as the player's health
	for (size_t i = 0; i < health; i++)
	{
		hand.push_back(gameState.drawCard());
	}
}

void Player::takeTurn()
{
	bangPlayed = false; // reset the bang played flag
	if (!passesTurn()) // if the player is not dead or in jail
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
		this->role == PlayerRole::SHERIF ? 5 : 4, // maximum health
		this->hand, this->equipment
	);
}

void Player::moveCardToEquipment(std::unique_ptr<Card> card)
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// if the card is the same type as a card in the equipment
		if(typeid(*card) == typeid(*equipment[i]))
		{
			gameState.discardCard(move(equipment[i])); // discard the previous equipment card
			equipment.erase(equipment.begin() + i); // remove the previous card from the equipment
			equipment.push_back(move(card)); // add the card to the equipment
			return;
		}
	}
	equipment.push_back(move(card));
}

void Player::replaceWeapon(std::unique_ptr<Card> card)
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// if there is a weapon card in the equipment
		if (WeaponCard* weapon = dynamic_cast<WeaponCard*>(equipment[i].get()))
		{
			gameState.discardCard(move(equipment[i])); // discard the previous weapon card
			equipment.erase(equipment.begin() + i); // remove the previous weapon card from the equipment
			equipment.push_back(move(card)); // add the card to the equipment
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
		// if the player has a prigione card
		if (typeid(*equipment[i]) == typeid(PrigioneCard))
		{
			gameState.discardCard(move(equipment[i])); // discard the prigione card
			equipment.erase(equipment.begin() + i); // remove the prigione card from the equipment
			unique_ptr<Card> card = gameState.drawCard(); // draw a card
			// if the card is a heart card the player is free
			if (card->color == CardColor::HEARTS)
			{
				gameState.discardCard(move(card));
				return true;
			}
			// if the card is not a heart card the player is in jail for this turn
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
	return "Unknown";
}

int Player::getMaximumHealth() const
{
	return role == PlayerRole::SHERIF ? 5 : 4; // maximum health
}

int Player::getHealth() const
{
	return health;
}

void Player::changeHealth(int value)
{
	health += value;
	if (health > getMaximumHealth()) 
		health = getMaximumHealth();
}

unique_ptr<Card> Player::handRandomCard()
{
	shuffle(hand.begin(), hand.end(), default_random_engine{ static_cast<unsigned int>(time(nullptr)) }); // shuffle the hand
	unique_ptr<Card> card = move(hand.back());
	hand.pop_back(); // remove the card from the hand
	return card;
}

unique_ptr<Card> Player::handEquipmentCard(int index)
{
	unique_ptr<Card> card = move(equipment[index]); 
	equipment.erase(equipment.begin() + index); // remove the card from the equipment
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
		// if the player has the same debuff card in the equipment
		if (typeid(*card) == typeid(*equipment[i]))
		{
			gameState.discardCard(move(equipment[i])); // discard the previous debuff card
			equipment.erase(equipment.begin() + i); // remove the previous debuff card from the equipment
			equipment.push_back(move(card)); // add the card to the equipment
			return;
		}
	}
	equipment.push_back(move(card));
}

bool Player::tryPlayBang()
{
	for (size_t i = 0; i < equipment.size(); i++)
		if (typeid(*equipment[i]) == typeid(VolcanicCard)) // if the player has a volcanic card he can play unlimited bang cards
			return true;

	if (bangPlayed)
		return false;

	bangPlayed = true;
	return true;
}

void Player::discardCard(int index)
{
	unique_ptr<Card> card = move(hand[index]);
	hand.erase(hand.begin() + index); // remove the card from the hand
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

	PlayerUIOutput::playerPublicScreen(role, this->health, getMaximumHealth(), this->equipment);
}

bool Player::defendBangEffect()
{
	for (size_t i = 0; i < equipment.size(); i++)
	{
		// if the player has a barrel card
		if (typeid(*equipment[i]) == typeid(BarileCard))
		{
			unique_ptr<Card> card = gameState.drawCard(); // draw a card
			// if the card is a heart card the player successfully defended
			if (card->color == CardColor::HEARTS)
			{
				gameState.discardCard(move(card));
				return true;
			}
		}
	}
	for (size_t i = 0; i < hand.size(); i++)
	{
		// if the player has a mancato card it is used to defend
		if (typeid(*hand[i]) == typeid(MancatoCard))
		{
			discardCard(i);
			return true;
		}
	}
	return false;
}

bool Player::returnFire()
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		// if the player has a bang card it is used to return fire
		if (typeid(*hand[i]) == typeid(BangCard))
		{
			discardCard(i);
			return true;
		}
	}
	return false;
}
