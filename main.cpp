#include "game.h"
#include "user.h"
#include "bot.h"
#include "user.h"

#include <string>

using namespace std;

void userCards(int phase, User &user, Game &game)
{
    if(phase == 1)
    {
        user.showPhase(phase);
        user.showCards(game.returnCards(2, 0), game.returnCards(2, 1));
        user.showCards(game.returnCards(3, 0), game.returnCards(3, 1));
        user.showPot(0);
    }
    else
    {
        user.showPhase(phase);

        user.showCards(game.returnCards(4, 0), game.returnCards(4, 1));
        user.showCards(game.returnCards(5, 0), game.returnCards(5, 1));
        user.showCards(game.returnCards(6, 0), game.returnCards(6, 1));

        if(phase == 3)
            user.showCards(game.returnCards(7, 0), game.returnCards(7, 1));
        else if(phase == 4)
        {
            user.showCards(game.returnCards(7, 0), game.returnCards(7, 1));
            user.showCards(game.returnCards(8, 0), game.returnCards(8, 1));
        }

        user.showPot(game.returnPot());
    }
}

int main()
{
    Game game;
    User user;
    Bot bot;

    bool nextRound = false;
    int winner = 0;
    int phase = 0;
    game.history = NULL;

    if(user.readGameMessage())
    {
        user.setMoney(game.getGameFromFile());
        bot.setMoney(1000 - user.returnMoney());
    }
    else
        user.instructionMessage();

    while(true)
    {
        //Finish game
        if(user.returnMoney() == 1000)
        {
            cout << user.showWinner(0);
            break;
        }
        else if(user.returnMoney() == 0)
        {
            cout << user.showWinner(1);
            break;
        }

        if(user.returnBet() == -1)
        {
            cout << user.showWinner(2);
            break;
        }


        //Initialize round
        game.setPot(0, 0);
        game.setRound(game.returnRound() + 1);
        nextRound = false;
        phase = 1;
        game.shuffleCards();
        game.addHandToHistory(game.returnRound(), game.history);
        user.nextRound(game.returnRound());
        winner = 0;

        while(phase != 5)
        {
            user.resetBet();
            bot.resetBet();

            //user cards depending on game phase, flop etc..
            userCards(phase, user, game);

            //user current user and bot stack
            user.displayStacks(user.returnMoney(), bot.returnMoney());

            user.playerDecisionOption(game.returnMinBet(), min(user.returnMoney(), bot.returnMoney()));

            while(true)
            {
                if(user.makeBet(game.returnMinBet(), min(user.returnMoney(), bot.returnMoney())) == 0)
                {
                    user.playerDecision(0);
                    nextRound = true;
                    winner = 2;
                    break;
                }
                else if(user.returnBet() == -1)
                {
                    break;
                }
                else if(user.returnBet() == max(game.returnMinBet(), bot.returnBet()))
                {
                    user.playerDecision(1);
                    if(bot.returnBet() != 0)
                        break;
                }
                else if(user.returnBet() > bot.returnBet())
                    user.playerDecision(2);

                if(bot.AIMakeBet(user.returnBet(), user.returnMoney()) == 0)
                {
                    //Bot pass - next round
                    user.botDecision(0, bot.returnBet());
                    nextRound = true;
                    winner = 1;
                    break;
                }
                else if(user.returnBet() == bot.returnBet())
                {
                    user.botDecision(1, bot.returnBet());
                    break;
                }
                else if(user.returnBet() < bot.returnBet())
                    user.botDecision(2, bot.returnBet());
            }

            if(user.returnBet() != -1)
            {
                game.setPot(user.returnBet(), bot.returnBet());
                if(winner == 1)
                    user.setMoney(user.returnMoney() + game.returnPot());
                else if(winner == 2)
                    bot.setMoney(bot.returnMoney() + game.returnPot());

                phase++;

                if(nextRound == true)
                    break;
                else
                    continue;
            }
            else
            {
                game.saveGameToFile(user.returnMoney());
                break;
            }
        }
    }
    if(user.returnBet() != -1)
        game.saveHistoryToFile(game.history);

    return 0;
}
