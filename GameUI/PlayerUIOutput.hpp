#pragma once
#include <string>
#include <vector>
#include "GameUIOutput.hpp"
#include "CardUIOutput.hpp"
#include "../CoreModul/Card.hpp"

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
private:
	static std::string renderCardVector(std::vector<std::unique_ptr<Card>>& cards);
};

