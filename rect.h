#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "grid.h"
// Goal of this class is to set an interface for horizontal, vertical and
// square within the grid.

class Rectangle {
    public: 
        Grid *grid;
        const int first;
        int current, currentIndex;
        bool comparison[9];
        Rectangle(Grid *_grid, int _first);
        virtual int next() = 0;
        virtual int prev() = 0;
        virtual int& operator[](int i) = 0;
        bool isSolved();
        void resetComparison();
        void resetView();
};


Rectangle::Rectangle(Grid *_grid, int _first) : first(_first){
    grid = _grid;
    resetView();
}


bool Rectangle::isSolved() {
    current = first;
    for (int i = 0; i < 9; ++i) {
        if(comparison[current-1] == false) 
            comparison[current-1] = true;
        else {
            //exception we made a mistake
            std::cout << "There's a mistake. End Program.";
        }
        current = next();
        ++currentIndex;
    }
    for (int i = 0; i < 9; ++i) {
        if (comparison[i] == false) {
            return false;
        }
    }
    return true;
}

void Rectangle::resetView() {
    current = first;
    currentIndex = 0;
    resetComparison();
}

void Rectangle::resetComparison() {
    for (int i = 0; i < 9; ++i) {
        comparison[i] = false;
    }
}

#endif
