#include <vector>

class Logic {
    private:
        int width, height;
        std::vector<std::vector<bool>>& cells; 
        
    public:
        Logic(int gridWidth, int gridHeight, std::vector<std::vector<bool>>& cellsRef);
        int countNeighbours(int x, int y);
        bool cellLogic(int x, int y, bool cellAlive);
    };