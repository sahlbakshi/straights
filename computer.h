#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
public:
    Computer();
    ~Computer(); 
    Computer(std::vector<Card> hand, std::vector<Card> discard, int score);
    bool play(Card &card, Table &table) override;
    bool discard(Card &card, Table &table) override;

private:
    bool findMove(Card &card, Table &table);
};

#endif