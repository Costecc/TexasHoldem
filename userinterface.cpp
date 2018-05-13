#include "userinterface.h"
#include "game.h"
#include "main.cpp"

UserInterface::UserInterface()
{
    cout << "Podaj nick, aby rozpoczac gre: ";
    cin >> nick;
}

void UserInterface::showCards(int phase, int kind, int colour)
{
    if(phase == 2)
        cout << "\n1 faza - Reka startowa: \n";
    if(phase == 4)
        cout << "\n2 faza - Flop: \n";
    if(phase == 7)
        cout << "\n3 faza - Turn: \n";
    if(phase == 8)
        cout << "\n4 faza - River: \n";

    switch(kind)
    {
        case 11: cout << "[ J"; break;
        case 12: cout << "[ D"; break;
        case 13: cout << "[ K"; break;
        case 14: cout << "[ A"; break;
    default: cout << "[ " << kind; break;
    }

    switch(colour)
    {
        case 0: cout << " kier ]"; break;
        case 1: cout << " karo ]"; break;
        case 2: cout << " pik ]"; break;
        case 3: cout << " trefl ]"; break;
    default: cout << " kier ]"; break;
    }

}

void UserInterface::showPot(int bBet, int pBet){
    cout << "\n+++ PULA WYNOSI " << bBet + pBet << "\n";
}

string UserInterface::showWinner(int winner)
{
    if(winner == 0)
        return "++++++++++++++++++++\nGratulacje! Wygrales gre!";
    else if(winner == 1)
        return "--------------------\nWygrywa przeciwnik. Sprobuj ponownie!";
    else
        return "--------------------\nWystapil blad. Uruchom ponownie aplikacje!";
}

void UserInterface::playerDecisionOption(int mBet, int money)
{
    cout<<"\nTwoja decyzja. Minimum: " << mBet << ", maksimum: " << money << ". 0 to pas.\n";
}

void UserInterface::botDecision(int botBet, int playerBet)
{
    if(botBet > playerBet)
        cout << "--- Komputer przebija do " << botBet << ".\n";
    if(botBet == playerBet)
        cout << "--- Komputer sprawdza (" << botBet << ").\n";
    if(botBet == 0)
        cout << "--- Komputer pasuje.\n";
}

void UserInterface::playerDecision(int decision)
{
    if(decision == 0)
        cout << "--- Zdecydowales sie spasowac.\n";
    else if(decision == 1)
        cout << "--- Zdecydowales sie sprawdzic.\n";
    else if(decision == 2)
        cout << "--- Zdecydowales sie przebic.\n";
}

void UserInterface::nextRound(int round)
{
    cout << "\n--- ROZPOCZYNAMY " << round << " ROZDANIE!\n";
}
