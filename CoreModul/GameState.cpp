#include "GameState.hpp"
using namespace std;

void GameStateControllor::mainGameLoop()
{
	while (!isGameEnd())
	{
		this->uiOut.nextPlayerWarningScreen();
		if (this->uiIn.waitForEnter())
		{
			shared_ptr<Player> currentPlayer = this->players[this->currentPlayerIndex];
			currentPlayer->takeTurn();
			this->currentPlayerIndex = (this->currentPlayerIndex + 1) % this->players.size();
		}
	}
}

bool GameStateControllor::isGameEnd()
{
	if (isSherifDead())
		return true;
	if (areBanditsDead())
		return true;
	return false;
}

bool GameStateControllor::isSherifDead()
{
	for (shared_ptr<Player> player : this->players)
	{
		if (player->role == PlayerRole::SHERIF && player->getHealth() <= 0)
			return true;
	}
	return false;
}

bool GameStateControllor::areBanditsDead()
{
	int banditCount = 0;
	int deadBanditCount = 0;
	for (shared_ptr<Player> player : this->players)
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

GameStateControllor& GameStateControllor::getInstance(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount)
{
	static GameStateControllor instance(uiOut, uiIn, playerCount);
	return instance;
}

GameState GameStateControllor::getCurrentState() const
{
	return this->currentState;
}

shared_ptr<Player> GameStateControllor::getPlayer(int index)
{
	if (index < 0 || index >= this->players.size())
		return nullptr;
	return this->players[index];
}

size_t GameStateControllor::playerCount()
{
	return this->players.size();
}

int GameStateControllor::getCurrentPlayerIndex() const
{
	return this->currentPlayerIndex;
}

GameStateControllor::GameStateControllor(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount) : uiOut(uiOut), uiIn(uiIn)
{
	initializeDeck();
	initializePlayers(playerCount);

	currentState = GameState::START;

	for (int i = 0; i < playerCount; i++)
	{
		if (players[i]->role == PlayerRole::SHERIF)
		{
			currentPlayerIndex = i;
			break;
		}
	}
}

std::vector<CardColor> GameStateControllor::generateDeckColors(int cardCount)
{
	int iterations = cardCount / 4;
	vector<CardColor> colors;
	for (int i = 0; i < iterations; i++)
	{
		colors.push_back(CardColor::HEARTS);
		colors.push_back(CardColor::DIAMONDS);
		colors.push_back(CardColor::CLUBS);
		colors.push_back(CardColor::SPADES);
	}

	int rest = cardCount % 4;
	if (rest > 0)
		colors.push_back(CardColor::HEARTS);
	if (rest > 1)
		colors.push_back(CardColor::DIAMONDS);
	if (rest > 2)
		colors.push_back(CardColor::CLUBS);

	return colors;
}

void GameStateControllor::startGame()
{
	this->uiOut.startGameScreen();
	if (this->uiIn.waitForEnter())
		this->uiOut.gameRulesScreen();

	if (this->uiIn.waitForEnter())
		mainGameLoop();
}

void GameStateControllor::endGame()
{
}

std::unique_ptr<Card> GameStateControllor::drawCard()
{
	if (deck.empty())
		return nullptr;

	auto card = move(deck.front());
	deck.pop_front();
	return card;
}

void GameStateControllor::discardCard(std::unique_ptr<Card> card)
{
	deck.push_back(move(card));
}

std::unique_ptr<Card> GameStateControllor::castDebuff(std::unique_ptr<Card> card)
{
	int targetIndex = CardUIInput::selectCastTarget(*this, *card);
	
	// The debuff was not casted
	if (targetIndex == -1)
		return move(card);

	players[targetIndex]->receiveDebuff(move(card));
	return nullptr;
}

void GameStateControllor::initializeDeck()
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
	shuffle(begin(deck), end(deck), default_random_engine{ static_cast<unsigned int>(time(nullptr)) });
}

void GameStateControllor::initializePlayers(int playerCount)
{
	players = vector<shared_ptr<Player>>(playerCount);

	// Randomize player roles
	PlayerRoleRandomizer prr = PlayerRoleRandomizer(playerCount);

	for (size_t i = 0; i < playerCount; i++)
	{
		players[i] = make_shared<Player>(*this, prr.getNextRole());
	}
}
