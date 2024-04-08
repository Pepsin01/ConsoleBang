#include "GameState.hpp"

GameStateControllor& GameStateControllor::getInstance(GameUIOutput& uiOut, int playerCount)
{
	static GameStateControllor instance(uiOut, playerCount);
	return instance;
}

GameState GameStateControllor::getCurrentState() const
{
	return this->currentState;
}

Player& GameStateControllor::getPlayer(int index)
{
	return this->players[index];
}

int GameStateControllor::playerCount()
{
	return this->players.size();
}

int GameStateControllor::getCurrentPlayerIndex() const
{
	return this->currentPlayerIndex;
}

GameStateControllor::GameStateControllor(GameUIOutput& uiOut, int playerCount) : uiOut(uiOut), players(playerCount)
{
	players = std::vector<Player>(playerCount);

	for (size_t i = 0; i < playerCount; i++)
	{
		players[i] = Player();
	}
}

void GameStateControllor::startGame()
{
}

void GameStateControllor::endGame()
{
}
