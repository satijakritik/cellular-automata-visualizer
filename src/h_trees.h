#pragma once
#include "automaton.h"

class HTrees : public Automaton {
public:
    HTrees(int width, int height);
    void update() override;
};

