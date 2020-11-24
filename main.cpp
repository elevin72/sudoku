#include "grid.h"
#include "rect.h"

/*
 * Pseudo:
 */


int main() {
    Puzzle sudoku;
    do {
        sudoku.getPuzzle();
            if (sudoku.isSolved() == false)
                sudoku.solve();
        sudoku.print();
        // some sort of check if want to do again
    } while (true);




}


