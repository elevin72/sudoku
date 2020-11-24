#ifndef HORIZONTAL_H
#define HORIZONTAL_H

#include "rect.h"

class Horizontal : public Rectangle {
    public: 
        Horizontal(Puzzle *_puzzle, int _first);
        int next();
        int prev();
        virtual int operator++() = 0;
        virtual int operator--() = 0;
        virtual int& operator[](int i);
};

int& Horizontal::operator[](int i){
    if (i < 0 || i > 8) {
        std::cout << "Out of range \n";
        return i;
    }
    int *cur = puzzle->grid[][];

}

int Horizontal::next() {
}


/* Horizontal::Horizontal(int square) { */
/*     first = current = square; */
/*     currentIndex = 0; */
/*     setComparison(); */
/* } */
#endif
