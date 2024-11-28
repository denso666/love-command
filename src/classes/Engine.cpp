#include "Engine.h"

Engine::Engine(void) { }
Engine::~Engine(void) { }

int Engine::display_deck(void) {
    try {
        cout << "DECk" << endl;
        for (auto c : this->deck) cout << "\t" << c << ": " << CardName[c] << endl;
    }
    catch (...) {
        cerr << "ERROR: <Engine::display_deck> An unexpected error occures" << endl;
        return 1;
    }

    return 0;
}

int Engine::set_players(void) {
    string tmp_name = "";

    // Try to set the name of both players
    try {
        for (short idx = 0; idx < MAX_PLAYERS; idx++) {
            getline(cin, tmp_name);

            // Verify name length
            if (tmp_name.length() > 0) this->players[idx].set_name(tmp_name);
            // Invalid input
            else {
                cout << "ERROR: Something goes wrong, try again!" << endl;
                idx--;
            }
        }

        cout << "SUCCESS: Correctly players name set" << endl;
    }
    catch(...) {
        cerr << "ERROR: <Engine::set_players> An unexpected error occures :(" << endl;
        return 1;
    }

    return 0;
}

int Engine::build_deck(void) {
    try {
        // Iterate through the card types to complete the deck
        for (int i = 0; i < NUMBER_CARD_TYPES; i++) {
            for (int j = 0; j < CardQty[i]; j++) {
                this->deck.push_back((Card)i);
            }
        }

        this->display_deck();

        // Create random engine
        random_device rd;
        default_random_engine rng(rd());

        // Shuffle deck
        shuffle(this->deck.begin(), this->deck.end(), rng);

        this->display_deck();
    }
    catch (...) {
        cerr << "ERROR: <Engine::build_deck> An unexpected error occures :(" << endl;
        return 1;
    }

    return 0;
}
