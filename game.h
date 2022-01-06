#ifndef GAME_H
#define GAME_H

#include "card.h"
#include "deck.h"
#include "table.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include <vector>

class Game {
    int seed;
    int curr;
    int frst;
    const int target;  // target score
    const int numOfPs; // players
    Deck deck;
    Table table;
    std::vector<int> scores;
    std::vector<Player*> players;

public:
    Game(int seed);
    ~Game();
    void ragequit();
    int  getTurn() const;
    bool getType() const;
    bool gameOver() const;
    bool roundNewOrOver() const;
    void resetTheRound();
    bool play(Card &card);
    bool discard(Card &card);
    void shuffleAndDeal();
    void addPlayer(bool type);
    const Deck& getDeck() const;
    const Table& getTable() const;
    const int gainScore(int nm) const;
    const int prevScore(int nm) const;
    const std::vector<int> getWinners() const;
    const std::vector<Card>& getYourHand() const;
    const std::vector<Card>& getDiscards(int nm) const;
    const std::vector<Card> getLegalPlays();

private:
    void getNextPlayer();
    bool targetScoreReached() const;
};

#endif