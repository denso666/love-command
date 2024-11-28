/**
 * @file Engine.h
 * @brief Declaration of the Engine class.
 *
 * This file contains the definition of the `Engine` class,
 * which provides whole functionalities for the game engine.
 */

#ifndef ENGINE_H
#define ENGINE_H

#include "Cards.h"
#include "Player.h"

#define MAX_PLAYERS 2

/**
 * @class Engine
 * @brief Game engine class.
 *
 * This clas is designed to handle all the game logics,
 * functionalities and parts. 
 */
class Engine {
    private:
        Player players[MAX_PLAYERS];
        vector<Card> deck;

        /**
         * @brief Display the whole deck.
         *
         * @return Return the status of the operation.
         */
        int display_deck(void);

    public:
        /**
         * @brief Default constructor.
         *
         * Initializes the class.
         */
        Engine(void);

        /** 
         * @brief Default constructor.
         *
         * Cleans up resources used by the class.
         */
        ~Engine(void);

        /**
         * @brief Set players name.
         *
         * @return Return the status of the operation.
         */
        int set_players(void);

        /**
         * @brief Build the whole deck (with the 8 card type) and prepare it (shuffles it).
         *
         * @return Return the status of the operation.
         */
        int build_deck(void);
};

#endif
