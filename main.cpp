#include "game.h"
#include "userinterface.h"
#include "user.h"
#include "bot.h"

#include <string>

using namespace std;

int main()
{
    Game game;
    UserInterface display;
    User player;
    Bot bot;
    int nextRound = false;
    int round = 1;
    game.history = NULL;

    while(true)
    {
        //Finish game
        if(player.returnMoney() == 1000)
        {
            display.showWinner(0);
            break;
        }
        else if(player.returnMoney() == 0)
        {
            display.showWinner(1);
            break;
        }

        display.nextRound(round);
        nextRound = false;

        game.shuffleCards();
        game.addHandToHistory(game.history);

        display.showCards(2, game.returnCards(2, 0), game.returnCards(2, 1));
        display.showCards(3, game.returnCards(3, 0), game.returnCards(3, 1));
        display.showPot(0, 0);

        display.playerDecisionOption(game.returnMinBet(), min(player.returnMoney(), bot.returnMoney()));//mozliwosc decyzji gracza wyswietla

        do
        {
            //Gracz pasuje (koniec rozdania)
            if(player.makeBet(game.returnMinBet(), bot.returnBet() + bot.returnMoney()) == 0)
            {
                display.playerDecision(0);
                nextRound = true;
                break;
            }
            else if(player.returnBet() == max(game.returnMinBet(), bot.returnBet()))
                display.playerDecision(1);
            else if(player.returnBet() > max(game.returnMinBet(), bot.returnBet()))
                display.playerDecision(2);

            //Wyrownanie zakladow, przejscie do nastepnej fazy gry (flop)
            if(player.returnBet() == bot.returnBet())
                break;

            display.botDecision(bot.AIMakeBet(player.returnBet(), player.returnMoney()), player.returnBet());

            //Bot pasuje
            if( (bot.returnBet() < player.returnBet()))
            {
                nextRound = true;
                break;
            }
        }while(player.returnBet() != bot.returnBet());

        game.setPot(bot.returnBet(), player.returnBet());

        if(nextRound == true)
        {
            if(player.returnBet() > bot.returnBet())
                player.setMoney(player.returnMoney() + game.returnPot());
            else
                bot.setMoney(bot.returnMoney() + game.returnPot());

            game.setPot(0, 0);
            player.resetBet();
            bot.resetBet();
            round++;
            continue;
        }
        else
            game.setPot(bot.returnBet(), player.returnBet());


        // -----------------------------
        // ----- 2 FAZA GRY - FLOP -----
        // -----------------------------
        display.showCards(4, game.returnCards(4, 0), game.returnCards(4, 1));
        display.showCards(5, game.returnCards(5, 0), game.returnCards(5, 1));
        display.showCards(6, game.returnCards(6, 0), game.returnCards(6, 1));
        display.showPot(player.returnBet(), bot.returnBet());

        display.playerDecisionOption(0, player.returnMoney());

        do
        {
            //Gracz pasuje (koniec rozdania)
            if(player.makeBet(game.returnMinBet(), bot.returnBet() + bot.returnMoney()) == 0)
            {
                display.playerDecision(0);
                nextRound = true;
                break;
            }
            else if(player.returnBet() == max(game.returnMinBet(), bot.returnBet()))
                display.playerDecision(1);
            else if(player.returnBet() > max(game.returnMinBet(), bot.returnBet()))
                display.playerDecision(2);

            //Wyrownanie zakladow, przejscie do nastepnej fazy gry (flop)
            if(player.returnBet() == bot.returnBet())
                break;

            display.botDecision(bot.AIMakeBet(player.returnBet(), player.returnMoney()), player.returnBet());

            //Bot pasuje
            if( (bot.returnBet() < player.returnBet()))
            {
                nextRound = true;
                break;
            }
        }while(player.returnBet() != bot.returnBet());

        if(nextRound == true)
        {
            game.setPot(0, 0);
            round++;
            continue;
        }
        else
            game.setPot(bot.returnBet(), player.returnBet());










        display.showCards(7, game.returnCards(7, 0), game.returnCards(7, 1));
        display.showCards(8, game.returnCards(8, 0), game.returnCards(8, 1));

        display.playerDecisionOption(0, player.returnMoney());
        player.makeBet(game.returnMinBet(), bot.returnBet() + bot.returnMoney());
        display.botDecision(bot.AIMakeBet(player.returnBet(), player.returnMoney()), player.returnBet());



        if(player.returnMoney() == 0 || player.returnMoney() == 1000)
            break;
    }
    return 0;
}
