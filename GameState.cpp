#include "GameState.hpp"
using namespace std;

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

GameStateControllor::GameStateControllor(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount) : uiOut(uiOut), uiIn(uiIn), players(playerCount)
{
	players = vector<shared_ptr<Player>>(playerCount);

	PlayerRoleRandomizer prr = PlayerRoleRandomizer(playerCount);

	for (size_t i = 0; i < playerCount; i++)
	{
		players[i] = make_shared<Player>(prr.getNextRole());
	}
}

void GameStateControllor::startGame()
{
	this->currentState = GameState::START;
	this->currentPlayerIndex = 0;
	this->uiOut.startGameScreen();
	if (this->uiIn.startGameScreen())
	{
		this->uiOut.gameRulesScreen();
	}
}

void GameStateControllor::endGame()
{
}
