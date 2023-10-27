# cellular-automata-visualizer

Designed and implemented a C++ Cellular Automata Visualization System that enables the real-time visualization of multiple 
life-like cellular automata on a split-screen graphical interface using the SFML library. The number of automata to be visualized 
dynamically changes the grid for split-screen display. The visualizer currently supports the following automata:
1. Conway's Game of Life (B3/S23)
2. Seeds (B2/S)
3. H-Trees (B1/S012345678)
4. Serviettes (B234/S)

Here, the rulestring B{}/S{} denotes the number of live neighbors needed for birth and survival of a cell respectively. Extending 
this for more automata is simple as the project follows a structured OOP approach.

## Setup

1. Install cmake from the terminal or from https://cmake.org/download/
2. Open a terminal window and enter the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
3. Run the executable using `./CellularAutomataVisualization`
   
