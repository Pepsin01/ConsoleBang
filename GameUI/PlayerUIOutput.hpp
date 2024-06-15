#pragma once
#include <string>
#include <vector>
#include "GameUIOutput.hpp"
#include "CardUIOutput.hpp"
#include "../CoreModul/Card.hpp"

class PlayerUIOutput
{
public:
	void playerPublicScreen(
		int playerNumber,
		const std::string& role,
		int health, int maxHealth,
		std::vector<std::unique_ptr<Card>>& equipment
	);
	void playerPrivateScreen(
		int playerNumber,
		const std::string& role,
		int health, int maxHealth,
		std::vector<std::unique_ptr<Card>>& hand,
		std::vector<std::unique_ptr<Card>>& equipment
	);
private:
	std::string renderCardVector(std::vector<std::unique_ptr<Card>>& cards);
};

