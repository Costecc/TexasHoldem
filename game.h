#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "userinterface.h"

using namespace std;

class Game
{
    struct Card
    {
        int kind;
        int colour;
    };
    int minBet;
    int pot;
public:
    Card deck[9];
    Game();
    ~Game();
    struct HandHistory
    {
        string hand;
        HandHistory *next;
    };
    HandHistory *history;
    int returnMinBet();
    void shuffleCards();
    int returnCards(int cardToReturn, int dataToReturn);
    int finishGame(int money);
    void setPot(int bBet, int pBet);
    int returnPot();
    void addHandToHistory(int round, HandHistory * &history);
    void saveGameToFile(HandHistory * & head);
};

#endif // GAME_H
