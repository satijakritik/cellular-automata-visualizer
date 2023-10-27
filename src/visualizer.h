#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "automaton.h"

class Visualizer {
public:
    Visualizer(const std::vector<Automaton*>& automatons);
    bool isRunning() const;
    void update();
    void render();

private:
    std::vector<Automaton*> automatons;
    sf::RenderWindow window;
    std::vector<sf::View> views;

    int numColumns;
    int numRows;    
};
