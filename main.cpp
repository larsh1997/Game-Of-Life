#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "logic.hpp"
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int CELL_SIZE = 20;
const int WIDTH = WINDOW_WIDTH/CELL_SIZE;
const int HEIGHT = WINDOW_HEIGHT/CELL_SIZE;

//TODO: Grid for background
//TODO: Grid should wrap around

int main()
{   
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Game of Life");
    window.setFramerateLimit(20);

    Grid grid(WIDTH, HEIGHT, CELL_SIZE);
    Logic logic(WIDTH, HEIGHT, grid.getCells());

    std::vector<std::vector<bool>> tmpCells; 
    tmpCells.resize(HEIGHT, std::vector<bool>(WIDTH, false));

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
            std::cout << "Grid X: " << (int)mousePosition.x/10 << " Grid Y: " << (int)mousePosition.y/10 << std::endl;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
   
            for(int w = 0; w < WIDTH; w++){
                for(int h = 0; h < HEIGHT; h++){
                    bool isAlive = logic.cellLogic(w, h, grid.getCellState(w, h));
                    tmpCells[h][w] = isAlive;
                }
            }
            for(int w = 0; w < WIDTH; w++){
                for(int h = 0; h < HEIGHT; h++){
                    grid.setCellState(w, h, tmpCells[h][w]);
                }
            }

        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            grid.clear();
        }
        
        window.clear(sf::Color(158,158,158));
        grid.draw(window);
        window.display();
    }
    return 0;
}