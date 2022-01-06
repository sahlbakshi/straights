#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <vector>
#include "card.h"
#include "table.h"

class Message {
public:
    void pileBoth(const std::vector<Card> &pile);
    void pileRank(const std::vector<Card> &pile);
    void invite(int x);
    void newRound(int x);
    void legalPlays(const std::vector<Card> &play);
    void yourHand(const std::vector<Card> &hand);
    void discards(int x, const std::vector<Card> &disc);
    void play(int x, const Card& card);
    void discard(int x, const Card& card);
    void notPlay();
    void notDiscard();
    void winners(const std::vector<int> wins);
    void score(int x, int s1, int s2);
    void rageQuit(int x);
    void gameTable(const Table &t);
};

#endif