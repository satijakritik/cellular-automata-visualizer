#include "automaton.h"
#include <cstdlib>

Automaton::Automaton(int width, int height)
    : width(width), height(height) {
    grid.resize(height, std::vector<bool>(width, false));
    nextGrid.resize(height, std::vector<bool>(width, false));
}

void Automaton::randomize() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = (rand() % 2 == 1);
        }
    }
}

void Automaton::centerSeed() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = false;
        }
    }
    grid[height / 2][width / 2] = true;
}

void Automaton::center4Seed() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = false;
        }
    }
    grid[height / 2][width / 2] = true;
    grid[height / 2][(width / 2) + 1] = true;
    grid[(height / 2) + 1][width / 2] = true;
    grid[(height / 2) + 1][(width / 2) + 1] = true;
}

void Automaton::update() {}

bool Automaton::isCellAlive(int x, int y) const {
    if (isValidCell(x, y)) {
        return grid[y][x];
    }
    return false;
}

int Automaton::getWidth() const {
    return width;
}

int Automaton::getHeight() const {
    return height;
}

bool Automaton::isValidCell(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int Automaton::countAliveNeighbors(int x, int y) const {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int neighborX = x + dx;
            int neighborY = y + dy;

            if (isValidCell(neighborX, neighborY) && grid[neighborY][neighborX]) {
                count++;
            }
        }
    }
    return count;
}