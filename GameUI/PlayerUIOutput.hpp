#pragma once
#include "../CoreModul/Card.hpp"
#include "CardUIOutput.hpp"
#include "GameUIInput.hpp"
#include "GameUIOutput.hpp"
#include <string>
#include <vector>

class PlayerUIOutput
{
public:
	static void playerPublicScreen(
		const std::string& role,
		int health, int maxHealth,
		std::vector<std::unique_ptr<Card>>& equipment
	);
	static void playerPrivateScreen(
		int playerNumber,
		const std::string& role,
		int health, int maxHealth,
		std::vector<std::unique_ptr<Card>>& hand,
		std::vector<std::unique_ptr<Card>>& equipment
	);
	static void playerDeadScreen();
	static void playerJailScreen();
	static void cannotPlayCardScreen(Card& card);
private:
	static std::string renderCardVector(std::vector<std::unique_ptr<Card>>& cards);
};

