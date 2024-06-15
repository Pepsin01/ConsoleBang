#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <ctime>
#include "Card.hpp"
#include "PlayerRole.hpp"
#include "GameState.hpp"

//class GameStateControllor;  // Forward declaration

class Player {
private:
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> equipment;
    int health;
    GameStateControllor& gameState;
public:
    const PlayerRole role;
    int getHealth() const;
    int calculateRange();

    void playCard(GameStateControllor& gameState, int cardIndex);
    Player(GameStateControllor& gameState, PlayerRole role);

    void takeTurn();
    void takeDamage(int damage);
    void showPublicProfile();

    std::unique_ptr<Card> handRandomCard();
    std::unique_ptr<Card> handEquipmentCard(int index);
    void receiveCard(std::unique_ptr<Card> card);
};

