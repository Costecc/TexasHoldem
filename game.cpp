#include "game.h"
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

Game::Game()
{
    minBet = 20;
}

Game::~Game()
{

}

int Game::returnMinBet(){

    return minBet;
}

void Game::shuffleCards()
{
    srand(time(0));
    Card newCard
    {
        newCard.kind = 0,
        newCard.colour = 0
    };

    int repeat = 0;

    for(int i = 0; i < 9; i++)
    {
        newCard.kind = rand()%13+2;
        newCard.colour = rand()%4+1;
        repeat = 0;

        for(int j = 0; j < i; j++)
        {
            if(newCard.kind == deck[j].kind)
            {
                if(newCard.colour == deck[j].colour)
                {
                    i--;
                    repeat++;
                    break;
                }
            }
        }

        if(repeat == 0) {
            deck[i].kind = newCard.kind;
            deck[i].colour = newCard.colour;
        }
    }
}

int Game::returnCards(int cardToReturn, int dataToReturn)
{
    if(dataToReturn == 0)
        return deck[cardToReturn].kind;
    else
        return deck[cardToReturn].colour;
}

int Game::finishGame(int money)
{
    if(money == 1000)
        return 0;
    else if(money == 0)
        return 1;
    else
        return 2;
}

void Game::setPot(int bBet, int pBet)
{
    if(bBet == 0 && pBet == 0)
        pot = 0;
    else
        pot += (bBet + pBet);
}

int Game::returnPot()
{
    return pot;
}

void Game::addHandToHistory(int round, HandHistory * & head)
{
  HandHistory * p, * e;

  e = new HandHistory;
  e->next = NULL;

  string hand;
  int kind, colour;

  hand = hand + "Runda nr " + to_string(round) + "\n";

  for(int i = 0; i < 9; i++)
  {
      kind = deck[i].kind;
      colour = deck[i].colour;

      if(i == 0)
          hand += "Karty gracza: ";
      if(i == 2)
          hand += "   Karty komputera: ";

      switch(kind)
      {
          case 11: hand += "[ J"; break;
          case 12: hand += "[ D"; break;
          case 13: hand += "[ K"; break;
          case 14: hand += "[ A"; break;
      default: hand += "[ ";
                hand += char(kind+47); break;
      }

      switch(colour)
      {
          case 0: hand += " kier ]"; break;
          case 1: hand += " karo ]"; break;
          case 2: hand += " pik ]"; break;
          case 3: hand += " trefl ]"; break;
      default: hand += " kier ]"; break;
      }
      if(i == 3)
          hand += "\nKarty wspolne: ";
  }

  e->hand = hand;
  p = head;
  if(p)
  {
     while(p->next) p = p->next;
     p->next = e;
  }
  else head = e;

  hand += "\n";
}

void Game::saveGameToFile(HandHistory * & head)
{
    HandHistory * p;
    p = head;

    string filename;
    cout << "Podaj nazwe pliku do zapisu BEZ ROZSZERZENIA: ";
    cin >> filename;

    filename += ".txt";

    ofstream file;
    file.open(filename);

    if(!file.is_open() || filename.length() < 5)
    {
        cout << "\nNie udalo sie utworzyc pliku!";
    }
    else
    {
        cout << "\nPoprawnie utworzono plik " << filename << "\n";

        while(p)
        {
          file << (p->hand);
          p = p->next;
        }
    }
    file.close();
}
