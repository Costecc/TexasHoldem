#include "user.h"

User::User()
{
    money = 500;
}

User::~User()
{

}

int User::returnMoney()
{
    return money;
}

void User::setMoney(int newMoney)
{
    money = newMoney;
}

int User::makeBet(int minBet, int maxBet) {
    int newBet = 0;
    do
    {
        while (cout << "Podaj kwote zakladu: " && !(cin >> newBet)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bledna kwota! Wprowadz ponownie: ";
        }

        if(newBet == 0)
            break;
    }while(newBet < minBet || newBet > min((money + bet), maxBet));

    if(newBet == 0)
        return 0;
    else
    {
        money = money - newBet + bet;
        bet = newBet;
        return bet;
    }
}

int User::returnBet()
{
    return bet;
}

void User::resetBet()
{
    bet = 0;
}
