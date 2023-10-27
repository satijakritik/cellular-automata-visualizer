#include "h_trees.h"

HTrees::HTrees(int width, int height) : Automaton(width, height) {}

void HTrees::update() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int aliveNeighbors = countAliveNeighbors(x, y);

            if (grid[y][x]) {
                // Survival
                nextGrid[y][x] = true;
            } else {
                // Birth
                nextGrid[y][x] = (aliveNeighbors == 1);
            }
        }
    }

    std::swap(grid, nextGrid);
}
