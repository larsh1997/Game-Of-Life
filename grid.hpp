/* grid.hpp */
#include <vector>
#include <SFML/Graphics.hpp>

class Grid {
    private:
        /* 2D Array, true = alive, false = dead */
        std::vector<std::vector<bool>> cells; 
        int width, height;
        /* Size of a cell in pixel */
        int cellSize;
        sf::RectangleShape cellShape;

    public:
        /* Constructur of class Grid */
        Grid(int gridWidth, int gridHeight, int cellSize);
        void draw(sf::RenderWindow& window);
        void setCellState(int x, int y, bool alive);
        /* const => does not alter Grid */
        bool getCellState(int x, int y) const;
        void clear();
        /* Inline functions (implementation directly in the header)
           const = Do not alter anything  */
        int getWidth() const { return width; }
        int getHeight() const { return height; }
        std::vector<std::vector<bool>>& getCells();
};