#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User
{
    string name;

protected:
    int money;
    int bet;

public:
    User();
    int returnMoney();
    void setMoney(int newMoney);
    int makeBet(int minBet, int maxBet);
    int returnBet();
    void resetBet();
};

#endif // USER_H
