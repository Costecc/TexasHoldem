#ifndef BOT_H
#define BOT_H

#include "user.h"
#include "player.h"

/**
 * @brief Klasa Bot zawiera specyficzne metody i parametry dotyczace zachowania bota
 * Dziedziczy po klasie Player, ktora zawiera wspolne cechy dla obu graczy
 */

class Bot : public Player
{
public:
    /**
     * @brief Konstruktor klasy Bot
     */
    Bot();
    /**
     * @brief Metoda AIMakeBet losujaca i zwracajaca wysokosc nowego zakladu bota
     * @param playerBet : Aktualna wysokosc zakladu bota
     * @param playerMoney : Aktualny stan konta bota
     * @return
     */
    int AIMakeBet(int playerBet, int playerMoney);
    /**
     * @brief Metoda returnAIBet zwracajaca aktualna wysokosc zakladu bota
     * @return
     */
    int returnAIBet();
};

#endif // BOT_H
