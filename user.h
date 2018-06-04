#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "player.h"

using namespace std;

/**
 * @brief Klasa User obsluguje zachowania gracza oraz odpowiada za interakcje z nim.
 * Dziedziczy po klasie Player
 */

class User : public Player
{
    string nick;

public:
    /**
     * @brief Konstruktor klasy User, inicjalizujacy nick gracza
     */
    User();
    /**
     * @brief Destruktor klasy User
     */
    ~User();
    /**
     * @brief Metoda wyswietlajaca biezacy stan konta obu graczy
     * @param userStack : Stan konta gracza realnego
     * @param botStack : Stan konta bota
     */
    void displayStacks(int userStack, int botStack);
    /**
     * @brief Metoda wyswietlajaca biezaca faze gry
     * @param phase : Faza gry, np. flop czy turn
     */
    void showPhase(int phase);
    /**
     * @brief Metoda pokazujaca dane karty
     * @param kind : Rodzaj karty np. walet
     * @param colour : Kolor karty np. pik
     */
    void showCards(int kind, int colour);
    /**
     * @brief Komunikat wyswietlajacy zwyciezce gry
     * @param winner : Zmienna informujaca o zwyciezcy
     */
    string showWinner(int winner);
    /**
     * @brief Komunikat odnosnie mozliwosci zakladu gracza
     * @param mBet : Minimalny zaklad jaki moze zagrac gracz
     * @param money : Maksymalny zaklad gracza
     */
    void playerDecisionOption(int mBet, int money);
    /**
     * @brief Komunikat wyswietlajacy decyzje bota
     * @param decision : Decyzja bota, np przebicie lub pas
     * @param botBet : Suma zakladu bota
     */
    void botDecision(int decision, int botBet);
    /**
     * @brief Komunikat wyswietlajacy decyzje gracza
     * @param decision : Decyzja gracza, np przebicie lub pas
     */
    void playerDecision(int decision);
    /**
     * @brief Podjecie decyzji przez gracza
     * @param minBet : Minimalny mozliwy zaklad gracza
     * @param maxBet : Maksymalny mozliwy zaklad gracza
     */
    int makeBet(int minBet, int maxBet);
    /**
     * @brief Komunikat o rozpoczeniu nastepnego rozdania
     * @param round : Numer biezacego rozdania
     */
    void nextRound(int round);
    /**
     * @brief Wyswietlenie biezacej puli
     * @param pot : Biezaca pula
     */
    void showPot(int pot);
    /**
     * @brief Komunikat pytajacy o wczytanie gry z pliku
     */
    bool readGameMessage();
    /**
     * @brief Krotka instrukcja na temat gry
     */
    void instructionMessage();
};

#endif // USER_H
