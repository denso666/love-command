#include "classes/Engine.h"

int main(int argc, char *argv[]) {
    Engine __engine;

    int output = (!__engine.set_players()) ? 0 : 1;
    output = (!__engine.build_deck()) ? 0 : 1;

    return output;
}
