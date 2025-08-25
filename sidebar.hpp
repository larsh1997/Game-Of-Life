#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class Sidebar{
    private:
        sf::RectangleShape background;
        int width;
        int height;
        int xPos;
    
    public:
        Sidebar(int sidebarWidth, int sidebarHeight, int xPosition);
        void draw(sf::RenderWindow& window);
};