#pragma once
#include "automaton.h"

class GameOfLife : public Automaton {
public:
    GameOfLife(int width, int height);
    void update() override;
};
