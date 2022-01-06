#include "computer.h"
using namespace std;

Computer::Computer() : Player{} { type = false; }

Computer::Computer(vector<Card> hand, vector<Card> discards, int score) :
Player{} {
    type = false;
    this->hand = hand;
    this->discards = discards;
    this->score = score;
} 

Computer::~Computer() {}

bool Computer::play(Card &card, Table &table) {
    if (findMove(card, table)) {
        removeFromHand(card);
        table.addToTable(card);
        return true;
    }
    return false;
}

bool Computer::discard(Card &card, Table &table) {
    if (!findMove(card, table)) {
        card = hand[0];
        removeFromHand(card);
        addToDiscards(card);
        score += card.getValue();
        return true;
    }
    return false;
}

bool Computer::findMove(Card &card, Table &table) {
    for (auto c : hand) {
        if (table.checkLegal(c)) {
            card = c;
            return true;
        }
    }
    return false;
}