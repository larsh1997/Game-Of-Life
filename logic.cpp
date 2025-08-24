#include "logic.hpp"

Logic::Logic(int gridWidth, int gridHeight, std::vector<std::vector<bool>>& cellsRef) 
    : width(gridWidth), height(gridHeight), cells(cellsRef) {}

bool Logic::cellLogic(int x, int y, bool cellAlive)
{
    int neighboursAlive = countNeighbours(x, y);
    if(cellAlive){
        if(neighboursAlive < 2){
            return false;
        }
        if(neighboursAlive == 2 || neighboursAlive == 3){
            return true;
        }
        return false;
    } else {
        if(neighboursAlive == 3){
            return true;
        }
        return false;
    }
}

int Logic::countNeighbours(int x, int y)
{   
    int neighboursAlive = 0;
    std::vector<std::pair<int, int>> offsets =
    {   /* {y, x} */
        {-1, -1}, 
        {-1,  0},
        {-1,  1},
        { 0,  1},
        { 1,  1},
        { 1,  0},
        { 1, -1},
        { 0, -1},
    };

    for (const auto& offset : offsets) {
        int neighborX = x + offset.second;  
        int neighborY = y + offset.first;  
        
        if (neighborX >= 0 && neighborX < width && 
            neighborY >= 0 && neighborY < height) {
            
            if (cells[neighborY][neighborX]) {
                neighboursAlive++;
            }
        }
    }

    return neighboursAlive;
}