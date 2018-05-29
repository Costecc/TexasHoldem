#include "bot.h"

Bot::Bot()
{
    money = 500;
}

int Bot::AIMakeBet(int playerBet, int playerMoney)
{
    int AIBet = rand()%20;
    int newBet = 0;

    if(playerBet <= money)
    {
        if(AIBet < 6)
        {
            newBet = 0;
        }
        else if(AIBet < 8)
        {
            newBet = min(money, playerBet);
        }
        else if(AIBet < 10)
        {
            newBet = min(money, 2*playerBet);
        }
        else if(AIBet < 13)
        {
            newBet = min(money, 3*playerBet);
        }
        else if(AIBet < 14)
        {
            newBet = min(money, 4*playerBet);
        }
        else if(AIBet < 15)
        {
            newBet = min(money, 5*playerBet);
        }
        else if(AIBet < 18)
        {
            newBet = min(money, (rand()%(3*playerBet)+playerBet));
        }
        else
            newBet = rand()%(money-playerBet)+playerBet;
    }

    //Bot can't play for more money than has player
    if(newBet < 0)
        newBet = 0;
    else
        newBet = min(newBet, playerMoney);

    if(newBet == 0)
        return 0;
    else
    {
        money = money - newBet + bet;
        bet = newBet;
        return bet;
    }
}

int Bot::returnAIBet()
{
    return bet;
}
