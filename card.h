#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

enum class Suit { CLUB, DIAMOND, HEART, SPADE }; 

enum class Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card {
    Suit suit;
    Rank rank;

public:
    Card();
    Card(Suit suit, Rank rank);
    Suit getSuit() const;
    Rank getRank() const;
    int getValue() const;
    std::string getSymbol() const;
    bool operator==(const Card &card) const;
    friend std::istream& operator>>(std::istream& in, Card &card);
};

std::ostream& operator<<(std::ostream& out, const Card &card);

#endif