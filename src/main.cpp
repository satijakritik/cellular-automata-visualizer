#include "visualizer.h"
#include "automaton.h"
#include "seeds.h"
#include "h_trees.h"
#include "game_of_life.h"
#include "serviettes.h"

int main() {
    std::vector<Automaton*> automatons;

    GameOfLife* game_of_life = new GameOfLife(100, 100);
    Seeds* seeds = new Seeds(100, 100);
    HTrees* h_trees = new HTrees(100, 100);
    Serviettes* serviettes = new Serviettes(100, 100);

    automatons.push_back(game_of_life);
    automatons.push_back(seeds);
    automatons.push_back(h_trees);
    automatons.push_back(serviettes);

    for (Automaton* automaton : automatons) {
        automaton->randomize();
    }

    seeds->center4Seed();
    h_trees->centerSeed();
    serviettes->center4Seed();

    Visualizer visualizer(automatons);

    while (visualizer.isRunning()) {
        for (Automaton* automaton : automatons) {
            automaton->update();
        }

        visualizer.update();
        visualizer.render();
    }

    // Clean up
    for (Automaton* automaton : automatons) {
        delete automaton;
    }

    return 0;
}
