#include "game.h"
#include "userinterface.h"
#include "user.h"
#include "bot.h"

#include <string>

using namespace std;

Game game;
UserInterface display;
User player;
Bot bot;

void displayCards(int phase)
{
    if(phase == 1)
    {
        display.showPhase(phase);
        display.showCards(game.returnCards(2, 0), game.returnCards(2, 1));
        display.showCards(game.returnCards(3, 0), game.returnCards(3, 1));
        display.showPot(0);
    }
    else
    {
        display.showPhase(phase);

        display.showCards(game.returnCards(4, 0), game.returnCards(4, 1));
        display.showCards(game.returnCards(5, 0), game.returnCards(5, 1));
        display.showCards(game.returnCards(6, 0), game.returnCards(6, 1));

        if(phase == 3)
            display.showCards(game.returnCards(7, 0), game.returnCards(7, 1));
        else if(phase == 4)
        {
            display.showCards(game.returnCards(7, 0), game.returnCards(7, 1));
            display.showCards(game.returnCards(8, 0), game.returnCards(8, 1));
        }

        display.showPot(game.returnPot());
    }
}

int main()
{
    bool nextRound = false;
    int winner = 0;
    int round = 0;
    int phase = 0;
    game.history = NULL;

    while(true)
    {
        //Finish game
        if(player.returnMoney() == 1000)
        {
            cout << display.showWinner(0);
            break;
        }
        else if(player.returnMoney() == 0)
        {
            cout << display.showWinner(1);
            break;
        }

        //Initialize round
        game.setPot(0, 0);
        round++;
        nextRound = false;
        phase = 1;
        game.shuffleCards();
        game.addHandToHistory(round, game.history);
        display.nextRound(round);
        winner = 0;

        while(phase != 5)
        {
            player.resetBet();
            bot.resetBet();

            //Display cards depending on game phase, flop etc..
            displayCards(phase);

            display.playerDecisionOption(game.returnMinBet(), min(player.returnMoney(), bot.returnMoney()));

            while(true)
            {
                if(player.makeBet(game.returnMinBet(), min(player.returnMoney(), bot.returnMoney())) == 0)
                {
                    display.playerDecision(0);
                    nextRound = true;
                    winner = 2;
                    break;
                }
                else if(player.returnBet() == max(game.returnMinBet(), bot.returnBet()))
                {
                    display.playerDecision(1);
                    if(bot.returnBet() != 0)
                        break;
                }
                else if(player.returnBet() > bot.returnBet())
                    display.playerDecision(2);

                if(bot.AIMakeBet(player.returnBet(), player.returnMoney()) == 0)
                {
                    //Bot pass - next round
                    display.botDecision(0, bot.returnBet());
                    nextRound = true;
                    winner = 1;
                    break;
                }
                else if(player.returnBet() == bot.returnBet())
                {
                    display.botDecision(1, bot.returnBet());
                    break;
                }
                else if(player.returnBet() < bot.returnBet())
                    display.botDecision(2, bot.returnBet());
            }

            game.setPot(player.returnBet(), bot.returnBet());
            if(winner == 1)
                player.setMoney(player.returnMoney() + game.returnPot());
            else if(winner == 2)
                bot.setMoney(bot.returnMoney() + game.returnPot());

            phase++;

            if(nextRound == true)
                break;
            else
                continue;
        }
        //player.setMoney(0);
    }

    game.saveGameToFile(game.history);

    return 0;
}
