#pragma once
#include "automaton.h"

class Seeds : public Automaton {
public:
    Seeds(int width, int height);
    void update() override;
};
