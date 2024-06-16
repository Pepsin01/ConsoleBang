#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <ctime>
#include "Card.hpp"
#include "PlayerRole.hpp"
#include "GameState.hpp"
#include "../GameUI/PlayerUIOutput.hpp"
#include "../GameUI/PlayerUIInput.hpp"
#include "../GameUI/GameUIOutput.hpp"
#include "../GameUI/GameUIInput.hpp"

//class GameStateControllor;  // Forward declaration

class Player {
private:
    int health;

    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> equipment;

    GameStateControllor& gameState;

    void showPrivateProfile();

    void moveCardToEquipment(std::unique_ptr<Card> card);
    void replaceWeapon(std::unique_ptr<Card> card);

    bool passesTurn();
    bool evaluatePrigione();

    std::string roleToString() const;
public:
    const PlayerRole role;
    int getHealth() const;
    int calculateRange() const;
    int getHandSize() const;
    GameStateControllor& getGameState() const;
    bool isDead() const;

    void playCard(int cardIndex);
    Player(GameStateControllor& gameState, PlayerRole role);

    void takeTurn();
    void takeDamage(int damage);
    void showPublicProfile();

    std::unique_ptr<Card> handRandomCard();
    std::unique_ptr<Card> handEquipmentCard(int index);
    void receiveCard(std::unique_ptr<Card> card);
    void receiveDebuff(std::unique_ptr<Card> card);
    void discardCard(int index);


};

