#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "logic.hpp"
#include "sidebar.hpp"
#include <iostream>

void performLogic(Logic& logic, Grid& grid, std::vector<std::vector<bool>>& tmpCells);

const int SIDEBAR_WIDTH = 200;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WINDOW_WIDTH/CELL_SIZE;
const int GRID_HEIGHT = WINDOW_HEIGHT/CELL_SIZE;

int main()
{   
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH  + SIDEBAR_WIDTH, WINDOW_HEIGHT}), "Game of Life");
    window.setFramerateLimit(40);

    Grid grid(GRID_WIDTH, GRID_HEIGHT, CELL_SIZE);
    Logic logic(GRID_WIDTH, GRID_HEIGHT, grid.getCells());
    Sidebar sidebar(SIDEBAR_WIDTH, WINDOW_HEIGHT, WINDOW_WIDTH);

    std::vector<std::vector<bool>> tmpCells; 
    tmpCells.resize(GRID_HEIGHT, std::vector<bool>(GRID_WIDTH, false));

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            grid.setCellState((int)mousePosition.x/CELL_SIZE, (int)mousePosition.y/CELL_SIZE , true);
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            performLogic(logic, grid, tmpCells);
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            grid.clear();
        }
        
        window.clear(sf::Color(158,158,158));
        grid.draw(window);
        sidebar.draw(window);
        window.display();
    }
    return 0;
}


void performLogic(Logic& logic, Grid& grid, std::vector<std::vector<bool>>& tmpCells){
    for(int w = 0; w < GRID_WIDTH; w++){
        for(int h = 0; h < GRID_HEIGHT; h++){
            bool isAlive = logic.cellLogic(w, h, grid.getCellState(w, h));
            tmpCells[h][w] = isAlive;
        }
    }
    for(int w = 0; w < GRID_WIDTH; w++){
        for(int h = 0; h < GRID_HEIGHT; h++){
            grid.setCellState(w, h, tmpCells[h][w]);
        }
    }
}