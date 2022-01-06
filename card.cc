#include "card.h"
using namespace std;

const string suits = "CDHS";
const string ranks = "A23456789TJQK";

Card::Card() {}

Card::Card(Suit suit, Rank rank) : suit{suit}, rank{rank} {}

Suit Card::getSuit() const { return suit; }

Rank Card::getRank() const { return rank; }

int Card::getValue() const { return static_cast<int>(rank) + 1; }

string Card::getSymbol() const {
    switch (rank) {
        case Rank::ACE:   return "A";
        case Rank::TEN:   return "T";
        case Rank::JACK:  return "J";
        case Rank::QUEEN: return "Q";
        case Rank::KING:  return "K";
        default: return to_string(getValue());
    }
}

bool Card::operator==(const Card &card) const {
    return suit == card.suit && rank == card.rank;
}

std::ostream& operator<<(std::ostream& out, const Card &card) {
    Suit suit = card.getSuit();
    Rank rank = card.getRank();
    int s = static_cast<int>(suit);
    int r = static_cast<int>(rank);
    out << ranks[r];
    out << suits[s];
    return out;
}

std::istream& operator>>(std::istream& in, Card &card) {
    string str;
    in >> str;
    int r = ranks.find(str[0]);
    int s = suits.find(str[1]);
    card.suit = static_cast<Suit>(s);
    card.rank = static_cast<Rank>(r);
    return in;
}