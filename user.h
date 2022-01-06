#ifndef USER_H
#define USER_H

#include "game.h"
#include "message.h"

class User {
    Game* game;
    Message* msg;

public:
    User(int seed);
    ~User();
    void startGame();
};

void discardsAndScores(Game*& game, Message*& msg);

#endif