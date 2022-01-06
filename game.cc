#include "game.h"
using namespace std;

Game::Game(int seed) : 
seed{seed}, target{80}, numOfPs{4}, deck{Deck()}, table{Table()}, scores{0,0,0,0} {}

Game::~Game() { for (auto p : players) delete p; }

int  Game::getTurn() const { return curr + 1; }

bool Game::getType() const { return players[curr]->getType(); }

const Deck& Game::getDeck() const { return deck; }

const Table& Game::getTable() const { return table; }

const int Game::prevScore(int nm) const { return scores[nm-1]; }

const int Game::gainScore(int nm) const { return players[nm-1]->getScore(); }

const vector<Card>& Game::getDiscards(int nm) const { 
    return players[nm-1]->getDiscards(); 
}

const vector<Card>& Game::getYourHand() const { 
    return players[curr]->getHand(); 
}

const vector<Card> Game::getLegalPlays() {
    return table.getLegalPlays(players[curr]->getHand());
}

bool Game::gameOver() const { 
    return roundNewOrOver() && targetScoreReached();
}

bool Game::roundNewOrOver() const {
    for (auto p : players) if (!p->getHand().empty()) return false;
    return true; 
}

bool Game::targetScoreReached() const {
    for (int i = 0; i < numOfPs; ++i) {
        if (players[i]->getScore() + scores[i] >= target) return true;
    }
    return false;
}

void Game::getNextPlayer() {
    if (curr == numOfPs - 1) curr = -1; 
    ++curr;
}

void Game::ragequit() {
    Player *hold = players[curr];
    players[curr] = new Computer{players[curr]->getHand(),
                    players[curr]->getDiscards(), players[curr]->getScore()};
    delete hold;
}

void Game::resetTheRound() {
    for (int i = 0; i < numOfPs; ++i) scores[i] += players[i]->getScore();
    for (auto p : players) p->clearPlayer();
    table.clearTable();
}

bool Game::play(Card &card) { 
    if (players[curr]->play(card, table)) {
        getNextPlayer();
        return true;
    }
    return false;
}

bool Game::discard(Card &card) { 
    if (players[curr]->discard(card, table)) {
        getNextPlayer();
        return true;
    }
    return false;
}

void Game::addPlayer(bool type) { 
    if (type) { 
        players.emplace_back(new Human{});
    } else {
        players.emplace_back(new Computer{}); 
    }
    ++curr;
}

void Game::shuffleAndDeal() {
    deck.shuffle(seed);
    int playerNum  = 0;
    int cardNumber = 0;
    int eachPlayer = 13;
    for (auto p: players) {
        while (eachPlayer > 0) {
            if (deck.getAt(cardNumber) == firstCard) {
                curr = frst = playerNum; }
            p->dealHand(deck.getAt(cardNumber)); 
            --eachPlayer;
            ++cardNumber;
        }
        ++playerNum;
        eachPlayer = 13;
    }
}

const vector<int> Game::getWinners() const {
    vector<int> winners;
    int win = players[0]->getScore() + scores[0];
    for (int i = 0; i < numOfPs; ++i) {
        win = min(win, players[i]->getScore() + scores[i]);
    }
    for (int i = 0; i < numOfPs; ++i) {
        if (win == players[i]->getScore() + scores[i]) {
            winners.emplace_back(i + 1);
        }
    }
    return winners;
}