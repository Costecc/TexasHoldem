#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

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
    int round;
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
    void setRound(int newRound);
    int returnRound();
    void addHandToHistory(int round, HandHistory * &history);
    void saveHistoryToFile(HandHistory * & head);
    int getGameFromFile();
    void saveGameToFile(int playerMoney);
};

#endif // GAME_H
