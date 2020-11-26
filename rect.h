#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "sudoku.h"
// Goal of this class is to set an interface for horizontal, vertical and
// square within the sudoku.

class Rectangle {
    public: 
        int index, gridIndex, firstIndex;/* x, y;*/
        bool inBounds, comparison[9];
        Rectangle();
        /* virtual int prevGridIndex() = 0; //does not change internals */
        void operator++(); // changes internals
        virtual int& operator[](int i) = 0;
        bool isSolved();
        void resetRectangle();
    /* private: */
        virtual int nextGridIndex(int index) = 0; //does not change internals
        virtual int getFirstIndex(int index) = 0; // same as above. 
        void resetComparison();
        int getValue(int index);
};

// I want to make a constructor that you can give any x,y pair in the grid and 
// it will return to you the requested view that contains that square
Rectangle::Rectangle() {
    index = gridIndex = firstIndex = -1;
    inBounds = true;
    resetRectangle();
}

int Rectangle::getValue(int index){
    return Sudoku::grid[index/9][index%9];
}
void Rectangle::operator++() {
    gridIndex = nextGridIndex(int index); // updates gridIndex
    if (gridIndex == -1)
        inBounds = false;
    index++;
}

/* int Sudoku::Rectangle::operator--() { */
/*     int prevIndexValue = prevIndex(); */
/*     if (prevIndexValue == -1) */
/*         inBounds = false; */
/*     index--; */
/*     x = nextIndexX(); */
/*     y = nextIndexY(); */
/* } */

bool Rectangle::isSolved() {
    int val, in = firstIndex;
    resetComparison();
    for (int i = 1; i < 9; ++i) {
        int val = getValue(in);
        if (val != 0)
            comparison[val-i] = true; // mark that it exists
        in = nextGridIndex(in);
    }
    for (int i = 0; i < 9; ++i) {
        if (comparison[i] == false) {
            return false;
        }
    }
    return true;
}

void Rectangle::resetRectangle() {
    value = Sudoku::grid[iy][ix];
    index = 0;
    resetComparison();
}

void Rectangle::resetComparison() {
    for (int i = 0; i < 9; ++i) {
        comparison[i] = false;
    }
}

#endif
