#include "human.h"
using namespace std;

Human::Human() : Player{} { type = true; }
 
Human::~Human() {}

bool Human::play(Card &card, Table &table) {
    if (table.checkLegal(card)) {
        removeFromHand(card);
        table.addToTable(card);
        return true;
    }
    return false;
}

bool Human::discard(Card &card, Table &table) {
    if (table.getLegalPlays(getHand()).empty()) {
        removeFromHand(card);
        addToDiscards(card);
        score += card.getValue();
        return true;
    }
    return false;
}