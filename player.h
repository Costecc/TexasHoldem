#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief Klasa Player zawiera parametry i metody opisujace/modyfikujace biezace
 * wysokosci zakladow graczy oraz ich stany konta
 */

class Player
{
protected:
    /**
     * @brief Parametr przechowuje biezacy stan konta gracza
     */
    int money;
    /**
     * @brief Parametr przechowuje wysokosc biezacego zakladu gracza
     */
    int bet;
public:
    /**
     * @brief Konstruktor klasy Player, inicjalizuje stan konta graczy
     */
    Player();
    /**
     * @brief Wirtualny destruktor klasy Player
     */
    virtual ~Player();
    /**
     * @brief Metoda zwracajaca biezacy stan konta gracza
     */
    int returnMoney();
    /**
     * @brief Metoda aktualizujaca biezacy stan konta gracza
     * @param newMoney : Nowa kwota do przypisania jako stan konta
     */
    void setMoney(int newMoney);
    /**
     * @brief Metoda zwracajaca wysokosc biezacego zakladu gracza
     */
    int returnBet();
    /**
     * @brief Metoda zerujaca zaklady graczy
     */
    void resetBet();
};

#endif // PLAYER_H
