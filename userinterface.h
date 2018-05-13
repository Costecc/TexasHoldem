#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class UserInterface
{
    string nick;

public:
    UserInterface();
    void showCards(int phase, int kind, int colour);
    string showWinner(int winner);
    void playerDecisionOption(int mBet, int money);
    void botDecision(int botBet, int playerBet);
    void playerDecision(int decision);
    void nextRound(int round);
    void showPot(int bBet, int pBet);
};

#endif // USERINTERFACE_H
