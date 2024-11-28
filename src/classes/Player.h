#ifndef PLAYER_H
#define PLAYER_H

#include "Cards.h"

class Player {
    private:
        string name;
        Card* cards[MAX_HAND];
        Card get_card(const int&) const;
        const int clean_card(const int&);

    public:
        Player(void);
        explicit Player(const Card&);

        void set_name(const string&);
        string get_name(void) const;

        Card play(const int&);
        string show_card(void) const;
        string display_cards(void) const;
        const int push_card(const int&);
};

#endif
