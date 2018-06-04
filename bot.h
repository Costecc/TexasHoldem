#ifndef BOT_H
#define BOT_H

#include "user.h"
#include "player.h"

class Bot : public Player
{
public:
    Bot();
    int AIMakeBet(int playerBet, int playerMoney);
    int returnAIBet();
};

#endif // BOT_H
