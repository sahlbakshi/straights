#ifndef TABLE_H
#define TABLE_H

#include "card.h"
#include <vector>

extern const Card firstCard;

class Table {
    int tableSize;
    std::vector<Card> clubs;
    std::vector<Card> diamonds;
    std::vector<Card> hearts;
    std::vector<Card> spades;

public:
    Table();
    ~Table();
    bool emptyTable();
    void clearTable();
    const int& getTableSize() const;
    bool checkLegal(Card &card);
    bool addToTable(Card &card);
    const std::vector<Card>& getClubs() const;
    const std::vector<Card>& getDiamonds() const;
    const std::vector<Card>& getHearts() const;
    const std::vector<Card>& getSpades() const;
    const std::vector<Card> getLegalPlays(const std::vector<Card> &hand);

private:
    std::vector<Card>& findPile(Suit suit);
    bool addOrCheck(Card &card, std::vector<Card> &pile, 
    bool what);
    
};

#endif