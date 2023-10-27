#pragma once

#include <vector>

enum AutomatonType {
    GAME_OF_LIFE,
    SEEDS,
    HTREES,
    SERVIETTES
};

class Automaton {
public:
    Automaton(int width, int height);
    void randomize();
    void centerSeed();
    void center4Seed();
    virtual void update();
    bool isCellAlive(int x, int y) const;
    int getWidth() const;
    int getHeight() const;

protected:
    int width;
    int height;
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;
    AutomatonType automatonType;

    bool isValidCell(int x, int y) const;
    int countAliveNeighbors(int x, int y) const;
};
