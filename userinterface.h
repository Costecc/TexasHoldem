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
    ~UserInterface();
    void showPhase(int phase);
    void showCards(int kind, int colour);
    string showWinner(int winner);
    void playerDecisionOption(int mBet, int money);
    void botDecision(int decision, int botBet);
    void playerDecision(int decision);
    void nextRound(int round);
    void showPot(int pot);
};

#endif // USERINTERFACE_H
