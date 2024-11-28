#ifndef CARDS_H
#define CARDS_H

#include "includes.h"

// General constants definitions
#define NUMBER_CARD_TYPES 9
#define DECK_SIZE 16
#define MAX_HAND 2

typedef enum Card_t : int {
    UNKNOWN     = 0,
    GUARD       = 1,
    PRIEST      = 2,
    BARON       = 3,
    HANDMAIN    = 4,
    PRINCE      = 5,
    KING        = 6,
    COUNTESS    = 7,
    PRINCESS    = 8
} Card;

const string CardName[NUMBER_CARD_TYPES]  = {
    "UNKNOWN",
    "GUARD",
    "PRIEST",
    "BARON",
    "HANDMAIN",
    "PRINCE",
    "KING",
    "COUNTESS",
    "PRINCESS"
};

const unsigned int CardQty[NUMBER_CARD_TYPES]  = {
    0,  // UNKNOWN
    5,  // GUARD
    2,  // PRIEST
    2,  // BARON
    2,  // HANDMAIN
    2,  // PRINCE
    1,  // KING
    1,  // COUNTESS
    1   // PRINCESS
};

#endif
