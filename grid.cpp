/* grid.cpp */
#include "grid.hpp"

/* Constructor: Initialize grid with given dimensions */
Grid::Grid(int gridWidth, int gridHeight, int cellSize) 
    : width(gridWidth), height(gridHeight), cellSize(cellSize) { /* Set class member values */
    
    /* Make the cells vector large enough to hold height elements,
       and fill each space with std::vector<bool>(width, false) 
       cells[0]          = [false, false, false, false, ...]  
       ...
       cells[height - 1] = [false, false, false, false, ...]  
    */
    cells.resize(height, std::vector<bool>(width, false));


    /* cellShape is a basic SFML rectangle shape */
    cellShape.setSize(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); /* -1 for grid lines */
    cellShape.setFillColor(sf::Color(61,252,48));
}

/* Call by reference. 
   In C++ when you pass an object to a function that expects a reference,
   C++ automatically creates the reference
*/
void Grid::draw(sf::RenderWindow& window) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (cells[y][x]) {
                /* Calculate screen coordinates from grid coordinates */
                cellShape.setPosition(sf::Vector2f(
                    static_cast<float>(x * cellSize), 
                    static_cast<float>(y * cellSize)));
                window.draw(cellShape);
            }
        }
    }
}

void Grid::setCellState(int x, int y, bool alive) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[y][x] = alive;
    }
}

bool Grid::getCellState(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return cells[y][x];
    }
    return false;
}

void Grid::clear() {
    for (auto& row : cells) {
        std::fill(row.begin(), row.end(), false);
    }
}