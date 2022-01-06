#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "table.h"
#include <vector>

class Player {
protected:
    int score;
    bool type;
    std::vector<Card> hand;
    std::vector<Card> discards;
    void removeFromHand(const Card& card);
    void addToDiscards(const  Card& card);

public:
    Player();
    int getScore() const;
    bool getType() const;
    virtual ~Player();
    void clearPlayer();
    void dealHand(const Card &card);
    virtual bool play(Card &card, Table &table) = 0;
    virtual bool discard(Card &card, Table &table) = 0;
    const std::vector<Card>& getHand() const;
    const std::vector<Card>& getDiscards() const;
};

#endif