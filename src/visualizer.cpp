#include "visualizer.h"

Visualizer::Visualizer(const std::vector<Automaton*>& automatons) : automatons(automatons) {
    int numAutomatons = automatons.size();

    numColumns = static_cast<int>(std::sqrt(numAutomatons));
    numRows = numAutomatons / numColumns;

    if (numColumns * numRows < numAutomatons) {
        numRows++;
    }

    window.create(sf::VideoMode(800, 800), "Cellular Automata");

    float subWindowWidth = 1.0f / numColumns;
    float subWindowHeight = 1.0f / numRows;

    for (size_t i = 0; i < automatons.size(); i++) {
        sf::View view = window.getDefaultView();

        int col = i % numColumns;
        int row = i / numColumns;
        float left = col * subWindowWidth;
        float top = row * subWindowHeight;

        view.setViewport(sf::FloatRect(left, top, subWindowWidth, subWindowHeight));
        views.push_back(view);
    }
}

bool Visualizer::isRunning() const {
    return window.isOpen();
}

void Visualizer::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Visualizer::render() {
    window.clear();

    for (size_t i = 0; i < automatons.size(); i++) {
        window.setView(views[i]);
        const Automaton* automaton = automatons[i];

        int width = automaton->getWidth();
        int height = automaton->getHeight();
        int cellSize = 8;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(automaton->isCellAlive(x, y) ? sf::Color::Black : sf::Color::White);
                window.draw(cell);
            }
        }
    }

    window.display();
}
