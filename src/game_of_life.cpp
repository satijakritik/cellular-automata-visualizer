#include "game_of_life.h"

GameOfLife::GameOfLife(int width, int height) : Automaton(width, height) {}

void GameOfLife::update() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int aliveNeighbors = countAliveNeighbors(x, y);

            if (grid[y][x]) {
                // Survival
                nextGrid[y][x] = (aliveNeighbors == 2 || aliveNeighbors == 3);
            } else {
                // Birth
                nextGrid[y][x] = (aliveNeighbors == 3);
            }
        }
    }

    std::swap(grid, nextGrid);
}
