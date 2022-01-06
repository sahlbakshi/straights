#include "deck.h" 
#include <random>
#include <algorithm>
using namespace std;

const int suitCount = 4;
const int rankCount = 13;
const int cardCount = 52;

Deck::Deck() {
    for (int s = 0; s < suitCount; ++s) {
        for (int r = 0; r < rankCount; ++r) {
            Suit suit = static_cast<Suit>(s);
            Rank rank = static_cast<Rank>(r);
            deck.emplace_back(Card{suit, rank});
        }
    } 
}

Deck::~Deck() { deck.clear(); }

const Card& Deck::getAt(int index) { return deck[index]; }

void Deck::shuffle(const int& seed) {
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

std::ostream& operator<<(std::ostream& out, const Deck &deck) {
    for (int i = 0; i < cardCount; ++i) {
        if (i && !(i % rankCount)) out << endl;
        out << deck.deck[i] << " "; 
    }
    return out;
}