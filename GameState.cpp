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

GameStateControllor::GameStateControllor(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount) : uiOut(uiOut), uiIn(uiIn)
{
	players = vector<shared_ptr<Player>>(playerCount);

	PlayerRoleRandomizer prr = PlayerRoleRandomizer(playerCount);

	for (size_t i = 0; i < playerCount; i++)
	{
		players[i] = make_shared<Player>(prr.getNextRole());
	}
	currentState = GameState::START;
	currentPlayerIndex = 0;
}

void GameStateControllor::startGame()
{
	this->uiOut.startGameScreen();
	if (this->uiIn.waitForEnter())
		this->uiOut.gameRulesScreen();
	if (this->uiIn.waitForEnter())
		{
		this->currentState = GameState::PLAYER_TURN;
	}
}

void GameStateControllor::endGame()
{
}
