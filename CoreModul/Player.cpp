#include "Player.hpp"
using namespace std;

int Player::calculateRange()
{
	int range = 1;
	/**/
	for (size_t i = 0; i < equipment.size(); i++)
	{
		if (typeid(*equipment[i]) == typeid(WeaponCard))
		{
			WeaponCard* weapon = dynamic_cast<WeaponCard*>(equipment[i].get());
			range += weapon->range;
		}
		if (typeid(*equipment[i]) == typeid(AppaloosaCard))
		{
			range++;
		}
	}
	/**/
	return range;
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
}

void Player::takeTurn()
{

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
	/**/
	shuffle(hand.begin(), hand.end(), default_random_engine{ static_cast<unsigned int>(time(nullptr)) });
	unique_ptr<Card> card = move(hand.back());
	hand.pop_back();
	return card;
	/**/
	//return nullptr;
}

unique_ptr<Card> Player::handEquipmentCard(int index)
{
	/**/
	unique_ptr<Card> card = move(hand[index]);
	hand.erase(hand.begin() + index);
	return card;
	/**/
	//return nullptr;
}

void Player::receiveCard(std::unique_ptr<Card> card)
{
	hand.push_back(move(card));
}

void Player::showPublicProfile()
{
}
