#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "player.h"

using namespace std;

class User : public Player
{
    string nick;

public:
    User();
    ~User();
    void displayStacks(int userStack, int botStack);
    void showPhase(int phase);
    void showCards(int kind, int colour);
    string showWinner(int winner);
    void playerDecisionOption(int mBet, int money);
    void botDecision(int decision, int botBet);
    void playerDecision(int decision);
    int makeBet(int minBet, int maxBet);
    void nextRound(int round);
    void showPot(int pot);
    bool readGameMessage();
    void instructionMessage();
};

#endif // USER_H
