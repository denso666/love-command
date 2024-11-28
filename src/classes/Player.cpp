#include "Player.h"

Player::Player(void) {
    this->name = "";
    this->cards[0] = nullptr;
    this->cards[1] = nullptr;
}

Player::Player(const Card &card) : Player() {
    this->cards[0] = new Card(card);
}

Card Player::get_card(const int &position) const {
    if (position > -1 and position < 2) {
        return *(this->cards[position]);
    }

    return Card::UNKNOWN;
}

const int Player::clean_card(const int &position) {
    // Non existing card position
    if (position > 1) {
        return 1;
    }

    // Drop card 0
    if (!position) {
        delete this->cards[0];
        this->cards[0] = this->cards[1];
    }
    // Drop card 1
    else {
        delete this->cards[1];
    }
    this->cards[1] = nullptr;

    return 0;
}

string Player::get_name(void) const {
    return this->name;
}

void Player::set_name(const string &name) {
    this->name = name;
}

Card Player::play(const int &position) {
    // Non existing card
    if (position > 1) return Card::UNKNOWN;
    // 5-7 or 6-7 cards combination
    if (
        (this->get_card(0) == Card::PRINCE || this->get_card(0) == Card::KING) &&
        this->get_card(1) == Card::COUNTESS
    ) {
        // If you don't want to drop the COUNTESS
        if (this->get_card(position) != Card::COUNTESS) return Card::UNKNOWN;
    }

    // Get played card
    Card played_card = this->get_card(position);

    // Drop the played card
    if (!this->clean_card(position)) return played_card;

    return Card::UNKNOWN;
}

string Player::show_card(void) const {
    ostringstream os;

    os << (int)this->get_card(0)<< " - " << CardName[(int)this->get_card(0)] << "\n";

    return os.str();
}

string Player::display_cards(void) const {
    ostringstream os;

    os << "0: " << (int)this->get_card(0) << " - " << CardName[(int)this->get_card(0)] << "\n"
       << "1: " << (int)this->get_card(1) << " - " << CardName[(int)this->get_card(1)] << "\n";

    return os.str();
}

const int Player::push_card(const int &card) {
    Card* new_card = new Card((Card)card);

    // Current card is major than the new one
    if ( this->get_card(0) > card) {
        this->cards[1] = this->cards[0];
        this->cards[0] = new_card;
    }
    // Current card is minor than the new one
    else this->cards[1] = new_card;

    return 0;
}
