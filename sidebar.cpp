#include "sidebar.hpp"

Sidebar::Sidebar(int sidebarWidth, int sidebarHeight, int xPosition) :
    width(sidebarWidth), height(sidebarHeight), xPos(xPosition) {

        background.setPosition(sf::Vector2f(xPosition, 0.0));
        background.setSize(sf::Vector2f(sidebarWidth, sidebarHeight));
        background.setFillColor(sf::Color(80, 80, 80));
        background.setOutlineThickness(2);
        background.setOutlineColor(sf::Color(40, 40, 40));
    }

void Sidebar::draw(sf::RenderWindow& window){
    window.draw(background);
}