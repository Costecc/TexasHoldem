#ifndef BOT_H
#define BOT_H

#include "user.h"

class Bot : public User
{
public:
    Bot();
    int AIMakeBet(int playerBet, int playerMoney);
    int returnAIBet();
};

#endif // BOT_H
