#include "user.h"

User::User()
{
    cout << "Podaj swoj nick: ";
    cin >> nick;
}

User::~User()
{

}

void User::displayStacks(int userStack, int botStack)
{
     cout<<"Twoj stack: " << userStack << ", stack bota: " << botStack << ".\n";
}

void User::showPhase(int phase)
{
    if(phase == 1)
        cout << "\n1 faza - Reka startowa: \n";
    if(phase == 2)
        cout << "\n2 faza - Flop: \n";
    if(phase == 3)
        cout << "\n3 faza - Turn: \n";
    if(phase == 4)
        cout << "\n4 faza - River: \n";
}

void User::showCards(int kind, int colour)
{
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

void User::showPot(int pot){
    cout << "\n+++ PULA WYNOSI " << pot << "\n";
}

string User::showWinner(int winner)
{
    if(winner == 0)
        return "++++++++++++++++++++\nGratulacje! Wygrales gre!\n";
    else if(winner == 1)
        return "--------------------\nWygrywa przeciwnik. Sprobuj ponownie!\n";
    else if(winner == 2)
        return "--------------------\nStan gry zostal zapisany. Do zobaczenia!\n";
    else
        return "--------------------\nWystapil blad. Uruchom ponownie aplikacje!\n";
}

void User::playerDecisionOption(int mBet, int money)
{
    cout<<"\nTwoja decyzja. Minimum: " << mBet << ", maksimum: " << money << ". 0 to pas.\n";

}

void User::botDecision(int decision, int botBet)
{
    if(decision == 2)
        cout << "--- Komputer przebija do " << botBet << ".\n";
    if(decision == 1)
        cout << "--- Komputer sprawdza (" << botBet << ").\n";
    if(decision == 0)
        cout << "--- Komputer pasuje.\n";
}

void User::playerDecision(int decision)
{
    if(decision == 0)
        cout << "--- Zdecydowales sie spasowac.\n";
    else if(decision == 1)
        cout << "--- Zdecydowales sie sprawdzic.\n";
    else if(decision == 2)
        cout << "--- Zdecydowales sie przebic.\n";
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

        if(newBet == -1 || newBet == 0)
            break;
    }while(newBet < minBet || newBet > min((money + bet), maxBet));

    if(newBet == -1)
    {
        bet = -1;
        return -1;
    }
    else if(newBet == 0)
        return 0;
    else
    {
        money = money - newBet + bet;
        bet = newBet;
        return bet;
    }
}



void User::nextRound(int round)
{
    cout << "\n--- ROZPOCZYNAMY " << round << " ROZDANIE!\n";
}

bool User::readGameMessage()
{
    char choice;
    cout << "Aby wczytac gre z pliku wpisz [ T ] (tak): ";
    cin >> choice;

    if(choice == 'T' || choice == 't')
        return true;

    return false;
}

void User::instructionMessage()
{
    cout << "\n--- Witaj w grze Poker " << nick << "!\n";
    cout << "--- Na poczatek Ty i wirtualny przeciwnik dostajecie po 500 zetonow\n";
    cout << "--- Dokonuj zakladow poprzez wpisywanie odpowiedniej kwoty\n";
    cout << "--- [ ! ] Mozesz zapisac stan ostatniej gry w kazdej chwili, wpisujac '-1'\n";
}
