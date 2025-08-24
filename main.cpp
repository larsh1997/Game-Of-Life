#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int CELL_SIZE = 10;

int main()
{   
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Game of Life");

    Grid grid(WINDOW_WIDTH / CELL_SIZE, WINDOW_HEIGHT / CELL_SIZE, CELL_SIZE);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "X: " << mousePosition.x << " Y: " << mousePosition.y << std::endl;
            grid.setCellState((int)mousePosition.x/10, (int)mousePosition.y/10 , true);
            std::cout << "Grid X: " << (int)mousePosition.x/10 << " Grid Y: " << (int)mousePosition.y/10 << std::endl;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            grid.clear();
        }
        
        window.clear(sf::Color(158,158,158));
        grid.draw(window);
        window.display();
    }
    return 0;
}