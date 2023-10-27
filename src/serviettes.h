#pragma once
#include "automaton.h"

class Serviettes : public Automaton {
public:
    Serviettes(int width, int height);
    void update() override;
};
