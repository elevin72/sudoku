#include "sudoku.h"
#include <iterator>
int Sudoku::count = 0;
int main() {
    Sudoku sudoku;
    sudoku.solveR(0); 
    sudoku.print();
    std::cout << "Took " << Sudoku::count << " guesses." << std::endl;
}


