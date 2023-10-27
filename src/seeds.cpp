#include "seeds.h"

Seeds::Seeds(int width, int height) : Automaton(width, height) {}

void Seeds::update() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int aliveNeighbors = countAliveNeighbors(x, y);

            if (grid[y][x]) {
                // Survival
                nextGrid[y][x] = false;
            } else {
                // Birth
                nextGrid[y][x] = (aliveNeighbors == 2);
            }
        }
    }

    std::swap(grid, nextGrid);
}
