#ifndef HORIZONTAL_H
#define HORIZONTAL_H

#include "rect.h"
// Some functionality I want out of this class:
// 1. I want it to be able to tell me which horizontal rectangle I'm from (trivial)
    // ie. give it some index and it returns the first index in that rectangle
// 2  I want to have a ++ or next that gives me the next value in the rectangle
// 3. I want it to be able to tell if a given rectangle is solved;
class h_rect : public Rectangle {
    public: 
        h_rect(int index);
        int getFirst(int index);
        int next(int index);
        bool isSolved(int index);
        
};

h_rect::h_rect(int index) {
    int first = getFirst(x, y);
     


}

int getFirst(index) {
    return index - (index % 9);
}
int next(index) {
    if (index % 9 == 8) // last in rectangle
        return -1;
    else
        return index+1;
}
bool isSolved(index) {
    int first = getFirst(index);
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        
        
    }
}
int& H_rect::operator[](int i){
    if (i < 0 || i > 8) {
        std::cout << "Out of range \n";
        return i;
    }
    int *cur = puzzle->grid[][];

}

int H_rect::next() {
}


/* H_rect::H_rect(int square) { */
/*     first = current = square; */
/*     currentIndex = 0; */
/*     setComparison(); */
/* } */
#endif
