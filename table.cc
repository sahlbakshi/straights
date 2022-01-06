#include "table.h"
using namespace std;

const Card firstCard{Suit::SPADE, Rank::SEVEN};

Table::Table() : tableSize{0} {}

Table::~Table() { this->clearTable(); }

const int& Table::getTableSize() const { return tableSize; }

bool Table::emptyTable() { return !tableSize; }

const vector<Card>& Table::getClubs() const { return clubs; }

const vector<Card>& Table::getDiamonds() const { return diamonds; }

const vector<Card>& Table::getHearts() const { return hearts; }

const vector<Card>& Table::getSpades() const { return spades; }

void Table::clearTable() { 
    tableSize = 0;
    clubs.clear();
    diamonds.clear();
    hearts.clear();
    spades.clear();
}

std::vector<Card>& Table::findPile(Suit suit) {
    switch (suit) {
        default:
        case Suit::CLUB: return clubs;
        case Suit::DIAMOND: return diamonds;
        case Suit::HEART: return hearts;
        case Suit::SPADE: return spades;
    }
}

bool Table::checkLegal(Card &card) {
    vector<Card> &pile = findPile(card.getSuit());
    return addOrCheck(card, pile, false);
}

bool Table::addToTable(Card &card) {
    vector<Card> &pile = findPile(card.getSuit());
    return addOrCheck(card, pile, true);
}

bool Table::addOrCheck(Card &card, std::vector<Card> &pile, bool what) {
    int value = card.getValue();
    Rank rank = card.getRank();
    enum Posn { FRONT, MIDDLE, BACK, NOPOS };
    Posn posn = Posn::NOPOS;
    if (emptyTable()) {
        if (card == firstCard) posn = MIDDLE;
    } else {
        if (pile.empty()) {
            if (rank == firstCard.getRank()) posn = MIDDLE;
        } else {
        if (pile.back().getValue() + 1 == value)  posn = BACK;
        if (pile.front().getValue() - 1 == value) posn = FRONT;
        }
    }
    if (posn == NOPOS)  return false; 
    if (what == false)  return true;
    if (posn == FRONT)  pile.insert(pile.begin(), card);
    if (posn == BACK)   pile.emplace_back(card);
    if (posn == MIDDLE) pile.emplace_back(card);
    ++tableSize;
    return true;
}

 const vector<Card> Table::getLegalPlays(const vector<Card> &hand) {
    vector<Card> plays;
    for (auto card : hand) {
        if (checkLegal(card)) plays.emplace_back(card);
    }
    return plays;
}