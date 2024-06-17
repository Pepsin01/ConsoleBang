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

class Player {
private:
    int health;
    bool bangPlayed;

    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> equipment;

    GameStateControllor& gameState;

    void showPrivateProfile();

    void moveCardToEquipment(std::unique_ptr<Card> card);
    void replaceWeapon(std::unique_ptr<Card> card);

    bool passesTurn();
    bool evaluatePrigione();

    std::string roleToString() const;
    int getMaximumHealth() const;


public:
    const PlayerRole role;
    int getHealth() const;
    int calculateRange() const;
    int calculateRangeWithoutWeapon() const;
    int calculateDistanceModifier() const;
    int getHandSize() const;
    int getEquipmentSize() const;
    GameStateControllor& getGameState() const;
    bool isDead() const;

    void playCard(int cardIndex);
    Player(GameStateControllor& gameState, PlayerRole role);

    void takeTurn();
    void changeHealth(int damage);
    void showPublicProfile();
    bool defendBangEffect();
    bool returnFire();
    bool tryPlayBang();

    std::unique_ptr<Card> handRandomCard();
    std::unique_ptr<Card> handEquipmentCard(int index);
    void receiveCard(std::unique_ptr<Card> card);
    void receiveDebuff(std::unique_ptr<Card> card);
    void discardCard(int index);
};

