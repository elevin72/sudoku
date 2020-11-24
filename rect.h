#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "grid.h"
// Goal of this class is to set an interface for horizontal, vertical and
// square within the puzzle.

class Rectangle {
    public: 
        Puzzle *puzzle;
        const int first;
        int value, index, indexInGrid;
        bool comparison[9];
        Rectangle(Puzzle *_puzzle, int x, int y);
        virtual int next() = 0;
        virtual int prev() = 0;
        virtual int& operator[](int i) = 0;
        bool isSolved();
        void resetComparison();
        void resetView();
};

// I want to make a constructor that you can give any x,y pair in the grid and 
// it will return to you the requested view that contains that square
Rectangle::Rectangle(Puzzle *_puzzle, int x, int y) : puzzle(_puzzle), 
    first(_puzzle->grid[y][x]){
    puzzle = _puzzle;
    resetView();
}


bool Rectangle::isSolved() {
    value = first;
    for (int i = 0; i < 9; ++i) {
        if(comparison[value-1] == false) 
            comparison[value-1] = true;
        else {
            //exception we made a mistake
            std::cout << "There's a mistake. End Program.";
        }
        value = next();
    }
    for (int i = 0; i < 9; ++i) {
        if (comparison[i] == false) {
            return false;
        }
    }
    return true;
}

void Rectangle::resetView() {
    value = first;
    index = 0;
    resetComparison();
}

void Rectangle::resetComparison() {
    for (int i = 0; i < 9; ++i) {
        comparison[i] = false;
    }
}

#endif
