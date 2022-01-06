#include "user.h"
#include <string>
#include <iostream>
using namespace std;

User::User(int seed) : 
game{new Game(seed)}, msg{new Message()} {}

User::~User() {
    delete game;
    delete msg;
}

void User::startGame() {
    Card card;
    bool flag = 1;
    bool begn = 0;
    int numOfPs=4;
    string typeOf;
    string command;
    for (int i = 1; i <= numOfPs; ++i) {
        msg->invite(i);
        cout << "> ";
        cin >> typeOf;
        if (typeOf == "h") game->addPlayer(true);
        if (typeOf == "c") game->addPlayer(false);
    }
    while (true) {
        if (game->gameOver()) break;
        if (game->roundNewOrOver()) {
            if (begn) discardsAndScores(game, msg);
            game->resetTheRound();
            game->shuffleAndDeal();
            msg->newRound(game->getTurn());
            begn = 1;
        }
        if (flag) {
            msg->gameTable(game->getTable());
            msg->yourHand(game->getYourHand());
            msg->legalPlays(game->getLegalPlays());
        }
        int curr = game->getTurn();
        if (game->getType()) {
            cout << "> ";
            cin >> command;
            if (command == "play") {
                cin >> card;
                flag = game->play(card);
                if (flag) {
                    msg->play(curr, card);
                } else {
                    msg->notPlay();
                }
            }
            else if (command == "discard") {
                cin >> card;
                flag = game->discard(card);
                if (flag) {
                    msg->discard(curr, card);
                } else {
                    msg->notDiscard();
                }
            }
            else if (command == "deck") {
                flag = 0;
                cout << game->getDeck() << endl;
            }
            else if (command == "ragequit") {
                flag = 0;
                game->ragequit();
                msg->rageQuit(game->getTurn());
            }
            else if (command == "quit") {
                return;
            }
        } 
        else 
        {
            flag = 1;
            if (game->play(card)) {
                msg->play(curr, card);
            } else {
                game->discard(card);
                msg->discard(curr, card);
            }
        }
    }
    discardsAndScores(game, msg);
    msg->winners(game->getWinners());
}

void discardsAndScores(Game*& game, Message*& msg) {
    for (int i = 1; i <= 4; ++i) {
        msg->discards(i, game->getDiscards(i));
        msg->score(i, game->prevScore(i), game->gainScore(i));
    }
}
