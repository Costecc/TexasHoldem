#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Klasa Game sluzy do obslugi zdarzen zwiazanych z przebiegiem gry: tasowanie kart, przechowywanie talii,
 * puli, rundy oraz zapisywanie i odczytywanie stanu gry z pliku czy eksportowanie historii rozdan po zakonczeniu gry.
 */

class Game
{
    /**
     * @brief Card : Struktura przechowujaca dane karty
     */
    struct Card
    {
        /**
         * @brief kind : Rodzaj karty, np. as lub dama
         */
        int kind;
        /**
         * @brief colour : Kolor karty, np. pik albo trefl
         */
        int colour;
    };
    /**
     * @brief minBet : Minimalna wysokosc zakladu jaka moze byc zagrana przez graczy
     */
    int minBet;
    /**
     * @brief pot : Aktualna pula w rozdaniu
     */
    int pot;
    /**
     * @brief round : Biezaca runda w rozgrywce
     */
    int round;
public:
    /**
     * @brief deck : Talia kart - tablica przechowujaca karty dla danego rozdania
     */
    Card deck[9];
    /**
     * @brief Game() : Konstruktor klasy Game
     */
    Game();
    /**
     * @brief Destruktor klasy Game
     */
    ~Game();
    /**
     * @brief Lista jednokierunkowa przechowujaca historie rozdan w danej grze
     */
    struct HandHistory
    {
        string hand;
        HandHistory *next;
    };
    /**
     * @brief history : Utworzona lista historie rozdan w danej grze
     */
    HandHistory *history;
    /**
     * @brief Metoda zwracajaca wysokosc minimalnego zakladu jaki gracze moga obstawic
     */
    int returnMinBet();
    /**
     * @brief Metoda sluzaca do tasowania kart
     */
    void shuffleCards();
    /**
     * @brief Metoda zwracajaca wybrana karte
     * @param cardToReturn : Rodzaj karty do zwrocenia, np. walet
     * @param dataToReturn : Kolor karty do zwrocenia np. karo
     */
    int returnCards(int cardToReturn, int dataToReturn);
    /**
     * @brief Metoda zwracajaca wynik gry
     * @param money : Stan konta gracza - jesli wynosi 0 lub 1000 - koniec gry
     */
    int finishGame(int money);
    /**
     * @brief Metoda sluzaca do aktualizacji wysokosci puli
     * @param bBet : Zaklad bota
     * @param pBet : Zaklad gracza
     */
    void setPot(int bBet, int pBet);
    /**
     * @brief Metoda zwracajaca aktualna wysokosc puli
     */
    int returnPot();
    /**
     * @brief Metoda ustawiajaca aktualny numer rundy
     * @param newRound : Numer oznaczajacy dotychczasowa ilosc rund
     */
    void setRound(int newRound);
    /**
     * @brief Metoda zwracajaca biezacy numer rundy
     */
    int returnRound();
    /**
     * @brief Metoda dodajaca biezace rozdanie do listy przechowujacej historie rozdan
     * @param round : Numer aktualnej rundy
     * @param history : Lista z zapisanymi rozdaniami
     */
    void addHandToHistory(int round, HandHistory * &history);
    /**
     * @brief Metoda zapisujaca historie rozdan do wybranego pliku
     * @param head : Wskaznik na liste z historia rozdan
     */
    void saveHistoryToFile(HandHistory * & head);
    /**
     * @brief Metoda wczytajaca dane na temat ostatniej gry z pliku
     */
    int getGameFromFile();
    /**
     * @brief Metoda zapisujaca stan gry do pliku celem pozniejszego odczytu
     * @param playerMoney : Aktualny stan konta gracza realnego
     */
    void saveGameToFile(int playerMoney);
};

#endif // GAME_H
