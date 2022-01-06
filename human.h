#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
public:
    Human();
    ~Human();
    bool play(Card &card, Table &table) override;
    bool discard(Card &card, Table &table) override;
};

#endif