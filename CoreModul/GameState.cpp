#include "GameState.hpp"
#include <algorithm>
#include <random>
#include <ctime>
#include "../GameUI/CardUIInput.hpp"
#include "PlayerRole.hpp"
#include "../Cards/AppaloosaCard.hpp"
#include "../Cards/BangCard.hpp"
#include "../Cards/BarileCard.hpp"
#include "../Cards/BirraCard.hpp"
#include "../Cards/CatBelouCard.hpp"
#include "../Cards/CarabineCard.hpp"
#include "../Cards/DiligenzaCard.hpp"
#include "../Cards/DuelloCard.hpp"
#include "../Cards/EmporioCard.hpp"
#include "../Cards/GatlingCard.hpp"
#include "../Cards/IndianiCard.hpp"
#include "../Cards/MancatoCard.hpp"
#include "../Cards/MustangCard.hpp"
#include "../Cards/PanicoCard.hpp"
#include "../Cards/PrigioneCard.hpp"
#include "../Cards/RemingtonCard.hpp"
#include "../Cards/SaloonCard.hpp"
#include "../Cards/SchofieldCard.hpp"
#include "../Cards/VolcanicCard.hpp"
#include "../Cards/WellsFargoCard.hpp"
#include "../Cards/WinchesterCard.hpp"

using namespace std;

void GameStateController::mainGameLoop()
{
	// Main game loop
	while (!isGameEnd())
	{
		this->uiOut.nextPlayerWarningScreen();
		if (GameUIInput::waitForEnter())
		{
			const shared_ptr<Player> currentPlayer = this->players[this->currentPlayerIndex]; // Get the current player
			currentPlayer->takeTurn(); // Let the current player take a turn
			this->currentPlayerIndex = (this->currentPlayerIndex + 1) % this->players.size(); // Move to the next player
		}
	}
	endGame();
}

bool GameStateController::isGameEnd() const
{
	if (isSherifDead()) // Check if the sherif is dead
		return true;
	if (areBanditsDead()) // Check if all bandits are dead
		return true;
	return false;
}

bool GameStateController::isSherifDead() const
{
	for (const shared_ptr<Player>& player : this->players)
	{
		if (player->role == PlayerRole::SHERIF && player->getHealth() <= 0)
			return true;
	}
	return false;
}

bool GameStateController::areBanditsDead() const
{
	int banditCount = 0;
	int deadBanditCount = 0;
	for (const shared_ptr<Player>& player : this->players)
	{
		if (player->role == PlayerRole::BANDIT)
		{
			banditCount++;
			if (player->getHealth() <= 0)
				deadBanditCount++;
		}
	}
	return deadBanditCount == banditCount;
}

GameStateController& GameStateController::getInstance(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount)
{
	static GameStateController instance(uiOut, uiIn, playerCount);
	return instance;
}

GameState GameStateController::getCurrentState() const
{
	return this->currentState;
}

shared_ptr<Player> GameStateController::getPlayer(int index)
{
	if (index < 0 || index >= static_cast<int>(this->players.size()))
		return nullptr;
	return this->players[index];
}

size_t GameStateController::playerCount() const
{
	return this->players.size();
}

int GameStateController::getCurrentPlayerIndex() const
{
	return this->currentPlayerIndex;
}

GameStateController::GameStateController(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount) : uiOut(uiOut), uiIn(uiIn)
{
	initializeDeck(); // Initializes all cards that will be used in the game
	initializePlayers(playerCount);
	
	currentState = GameState::START;

	// Sheriff is the first player
	for (int i = 0; i < playerCount; i++)
	{
		if (players[i]->role == PlayerRole::SHERIF)
		{
			currentPlayerIndex = i;
			break;
		}
	}
}

std::vector<CardColor> GameStateController::generateDeckColors(int cardCount)
{
	const int iterations = cardCount / 4; 
	vector<CardColor> colors;
	for (int i = 0; i < iterations; i++)
	{
		colors.push_back(CardColor::HEARTS);
		colors.push_back(CardColor::DIAMONDS);
		colors.push_back(CardColor::CLUBS);
		colors.push_back(CardColor::SPADES);
	}

	// If the number of cards is not divisible by 4, add the remaining colors
	int rest = cardCount % 4;
	if (rest > 0)
		colors.push_back(CardColor::HEARTS);
	if (rest > 1)
		colors.push_back(CardColor::DIAMONDS);
	if (rest > 2)
		colors.push_back(CardColor::CLUBS);

	return colors;
}

void GameStateController::startGame()
{
	this->uiOut.startGameScreen();
	if (GameUIInput::waitForEnter())
		this->uiOut.gameRulesScreen();

	if (GameUIInput::waitForEnter())
		mainGameLoop();
}

void GameStateController::endGame() const
{
	this->uiOut.endGameScreen();
}

std::unique_ptr<Card> GameStateController::drawCard()
{
	if (deck.empty())
		return nullptr;

	auto card = move(deck.front());
	deck.pop_front();
	return card;
}

void GameStateController::discardCard(std::unique_ptr<Card> card)
{
	deck.push_back(move(card));
}

std::unique_ptr<Card> GameStateController::castDebuff(std::unique_ptr<Card> card)
{
	int targetIndex = CardUIInput::selectCastTarget(*this, *card);
	
	// The debuff was not casted
	if (targetIndex == -1)
		return move(card);

	players[targetIndex]->receiveDebuff(move(card));
	return nullptr;
}

int GameStateController::calculateDistance(int attackerIndex, int defenderIndex)
{
	int direct_distance = abs(attackerIndex - defenderIndex); // Direct distance between the attacker and the defender
	int wrapped_distance = static_cast<int>(players.size()) - direct_distance; // Complementary distance if we assume the end of the vector is connected to the beginning

	return min(direct_distance, wrapped_distance) + getPlayer(defenderIndex)->calculateDistanceModifier(); // Return the minimum distance plus the distance modifier of the defender
}

void GameStateController::initializeDeck()
{
	// Constants for the number of cards in the deck
	int totalCardCount = APPALOOSA_CARD_COUNT + BANG_CARD_COUNT + BARILE_CARD_COUNT + BIRRA_CARD_COUNT + CARABINE_CARD_COUNT +
		CATBELOU_CARD_COUNT + DILIGENZA_CARD_COUNT + DUELLO_CARD_COUNT + EMPORIO_CARD_COUNT + GATLING_CARD_COUNT +
		INDIANI_CARD_COUNT + MANCATO_CARD_COUNT + MUSTANG_CARD_COUNT + PANICO_CARD_COUNT + PRIGIONE_CARD_COUNT +
		REMINGTON_CARD_COUNT + SALOON_CARD_COUNT + SCHOFIELD_CARD_COUNT + VOLCANIC_CARD_COUNT + WELLS_FARGO_CARD_COUNT +
		WINCHESTER_CARD_COUNT;

	// Generate colors for the deck
	vector<CardColor> colors = generateDeckColors(totalCardCount);

	// Add cards to the deck
	addCardsToDeck<AppaloosaCard>(deck, *this, colors, APPALOOSA_CARD_COUNT);
	addCardsToDeck<BangCard>(deck, *this, colors, BANG_CARD_COUNT);
	addCardsToDeck<BarileCard>(deck, *this, colors, BARILE_CARD_COUNT);
	addCardsToDeck<BirraCard>(deck, *this, colors, BIRRA_CARD_COUNT);
	addCardsToDeck<CarabineCard>(deck, *this, colors, CARABINE_CARD_COUNT);
	addCardsToDeck<CatBelouCard>(deck, *this, colors, CATBELOU_CARD_COUNT);
	addCardsToDeck<DiligenzaCard>(deck, *this, colors, DILIGENZA_CARD_COUNT);
	addCardsToDeck<DuelloCard>(deck, *this, colors, DUELLO_CARD_COUNT);
	addCardsToDeck<EmporioCard>(deck, *this, colors, EMPORIO_CARD_COUNT);
	addCardsToDeck<GatlingCard>(deck, *this, colors, GATLING_CARD_COUNT);
	addCardsToDeck<IndianiCard>(deck, *this, colors, INDIANI_CARD_COUNT);
	addCardsToDeck<MancatoCard>(deck, *this, colors, MANCATO_CARD_COUNT);
	addCardsToDeck<MustangCard>(deck, *this, colors, MUSTANG_CARD_COUNT);
	addCardsToDeck<PanicoCard>(deck, *this, colors, PANICO_CARD_COUNT);
	addCardsToDeck<PrigioneCard>(deck, *this, colors, PRIGIONE_CARD_COUNT);
	addCardsToDeck<RemingtonCard>(deck, *this, colors, REMINGTON_CARD_COUNT);
	addCardsToDeck<SaloonCard>(deck, *this, colors, SALOON_CARD_COUNT);
	addCardsToDeck<SchofieldCard>(deck, *this, colors, SCHOFIELD_CARD_COUNT);
	addCardsToDeck<VolcanicCard>(deck, *this, colors, VOLCANIC_CARD_COUNT);
	addCardsToDeck<WellsFargoCard>(deck, *this, colors, WELLS_FARGO_CARD_COUNT);
	addCardsToDeck<WinchesterCard>(deck, *this, colors, WINCHESTER_CARD_COUNT);

	// Shuffle the deck
	shuffle(deck.begin(), deck.end(), default_random_engine(static_cast<unsigned int>(time(nullptr))));
}

void GameStateController::initializePlayers(const int playerCount)
{
	players = vector<shared_ptr<Player>>(playerCount);

	// Randomize player roles
	PlayerRoleRandomizer prr = PlayerRoleRandomizer(playerCount);

	for (int i = 0; i < playerCount; i++)
	{
		players[i] = make_shared<Player>(*this, prr.getNextRole());
	}
}
