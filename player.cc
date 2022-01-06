#include "player.h"
#include <algorithm> 
using namespace std;

Player::Player() : score{0} {}

Player::~Player() {}

bool Player::getType() const { return type; }

int Player::getScore() const { return score; }

const vector<Card>& Player::getHand() const { return hand; }

const vector<Card>& Player::getDiscards() const { return discards; }

void Player::addToDiscards(const Card& card) {
    discards.emplace_back(card); 
}

void Player::dealHand(const Card& card) { 
    hand.emplace_back(card); 
}

void Player::removeFromHand(const Card &card) {
    hand.erase(std::remove(hand.begin(), hand.end(), card), hand.end());
}

void Player::clearPlayer() {
    score = 0;
    hand.clear();
    discards.clear();
}