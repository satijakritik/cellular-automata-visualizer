cmake_minimum_required(VERSION 3.0)
project(CellularAutomataVisualization)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(SOURCES
    src/main.cpp
    src/automaton.cpp
    src/seeds.cpp
    src/h_trees.cpp
    src/game_of_life.cpp
    src/serviettes.cpp
    src/visualizer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(CellularAutomataVisualization sfml-graphics)