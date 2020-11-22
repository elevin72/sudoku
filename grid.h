#ifndef GRID_H
#define GRID_H
#include <iostream>
class Grid {
    public:
        int grid[9][9]; // written backwards. grid[y][x]
        Grid();
        void InputByRow();
        void Print();
        bool isSolved();
};

Grid::Grid() {
    for (int i = 0; i < 81; ++i) {
        grid[i/9][i%9] = -1;
    }
}

void Grid::InputByRow() {
    for (int i = 0; i < 9; ++i) {
        std::cout << "Please input row 1: \n";
        for (int i = 0; i < 9; ++i) {
            std::cin >> 


    for (int i = 0; i < 9; ++i) {
       }

    }

}




#endif
