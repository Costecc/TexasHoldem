#include <iostream>
#include "player.h"

using namespace std;

Player::Player()
{
    money = 500;
}
Player::~Player()
{

}

int Player::returnMoney()
{
    return money;
}

void Player::setMoney(int newMoney)
{
    money = newMoney;
}

int Player::returnBet()
{
    return bet;
}

void Player::resetBet()
{
    bet = 0;
}
