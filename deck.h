#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <iostream>

class Deck {
    std::vector<Card> deck;

public:
    Deck();
    ~Deck();
    void shuffle(const int& seed);
    const Card& getAt(int index);
    friend std::ostream& operator<<(std::ostream& out, const Deck &deck);
};

#endif