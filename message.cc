#include "message.h"
using namespace std;

void Message::pileBoth(const vector<Card> &pile) {
    for (auto card : pile) cout << " " << card;
    cout << endl;
}

void Message::pileRank(const vector<Card> &pile) {
    for (auto card : pile) cout << " " << card.getSymbol();
    cout << endl;
}

void Message::invite(int x) {
    cout << "Is Player" << x << " a human (h) or a computer (c)?";
    cout << endl;
}

void Message::newRound(int x) {
    cout << "A new round begins. It's Player" << x << "'s turn to play.";
    cout << endl;
}

void Message::legalPlays(const vector<Card> &play) {
    cout << "Legal plays:";
    pileBoth(play);
}

void Message::yourHand(const vector<Card> &hand) {
    cout << "Your hand:";
    pileBoth(hand);
}

void Message::play(int x, const Card& card) {
    cout << "Player" << x << " plays " << card << "." << endl;
}

void Message::discard(int x, const Card& card) {
    cout << "Player" << x << " discards " << card << "." << endl;
}

void Message::notPlay() {
    cout << "This is not a legal play." << endl;
}

void Message::notDiscard() {
    cout << "You have a legal play. You may not discard." << endl;
}

void Message::winners(const vector<int> wins) {
    for (auto x : wins) cout << "Player" << x << " wins!" << endl;
}


void Message::rageQuit(int x) {
    cout << "Player" << x << " ragequits.";
    cout << " A computer will now take over." << endl;
}

void Message::gameTable(const Table &t) {
    cout << "Cards on the table:";
    cout << endl;
    cout << "Clubs:";
    pileRank(t.getClubs());
    cout << "Diamonds:";
    pileRank(t.getDiamonds());
    cout << "Hearts:";
    pileRank(t.getHearts());
    cout << "Spades:";
    pileRank(t.getSpades());
}

void Message::discards(int x, const vector<Card> &disc) {
    cout << "Player" << x << "'s discards:";
    pileBoth(disc);
}

void Message::score(int x, int s1, int s2) {
    cout << "Player" << x << "'s score: " << s1 << " + " << s2;
    cout << " = " << s1+s2 << endl;
}