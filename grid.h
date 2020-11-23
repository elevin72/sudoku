#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
class Puzzle {
    public:
        int grid[9][9]; // written backwards. grid[y][x]
        Puzzle();
        void InputByRow();
        void Print();
        bool isSolved();
};

Puzzle::Puzzle() {
    for (int i = 0; i < 81; ++i) {
        grid[i/9][i%9] = -1;
    }
}

void Puzzle::InputByRow() {
    for (int i = 0; i < 9; ++i) {
        std::cout << "Please input row 1: \n";
        for (int i = 0; i < 9; ++i) {
            std::cin >> 


    for (int i = 0; i < 9; ++i) {
       }

    }

}




#endif
