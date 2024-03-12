#include "GameState.hpp"

GameState& GameState::getInstance()
{
	static GameState instance;
	return instance;
}

void GameState::startGame()
{
}

void GameState::endGame()
{
}
