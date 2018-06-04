#ifndef PLAYER_H
#define PLAYER_H

class Player
{
protected:
    int money;
    int bet;
public:
    Player();
    virtual ~Player();
    int returnMoney();
    void setMoney(int newMoney);
    int returnBet();
    void resetBet();
};

#endif // PLAYER_H
