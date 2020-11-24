#ifndef PUZZLE_H
#define PUZZLE_H
#include <functional>
#include <iostream>
#include <iterator>
class Puzzle {
    public:
        int grid[9][9]; // written backwards. grid[y][x]
        Puzzle();
        void InputByRow();
        void Print();
        bool isSolved();
        void print();
};

Puzzle::Puzzle() {
    for (int i = 0; i < 81; ++i) {
        grid[i/9][i%9] = 0;
    }
}

void Puzzle::InputByRow() {
    int n;
    std::cout << "Input your puzzle here. Empty spaces are denoted as 0\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << "Please input row " << i-1 << ":\n";
        for (int j = 0; j < 9; ++j) {
            do {
                std::cin >> n;
                if (n > 0 && n <= 9) {
                    std::cout << "Illegal number!\n";
                    break;
                }
            } while (true);
            grid[j][i] = n;
        }
    }
}
/*
   ─
   ┌─────────────────────────┐
   1│ 
   ┃
   │
   ┏━┯━┯━┳━┯━┯━┳━┯━┯━┓     ┳
   ┃1│2│3┃4│5│6┃7│8│9┃
   ┠─┼─┼─╂─┼─┼─╂─┼─┼─┨             ─┼  ─┴  ─╂       

   ┣━━━┿━┿━╋━┿━┿━╋━┿━┿━┫              ━┿  ━╋ 	━
   ┃ 1 │
   ┗━━━┷━┷━┻━┷━┷━┻━┷━┷━┛     ━┷  ━┻  ━┛━

   i1 2 3 4 5 6 7 8 9 
   char top[] = "┏━┯━┯━┳━┯━┯━┳━┯━┯━┓";

   char middleThin[] = "┠─┼─┼─╂─┼─┼─╂─┼─┼─┨";

   char middleThick[] = "┣━┿━┿━╋━┿━┿━╋━┿━┿━┫";

   char bottom[] = "┗━┷━┷━┻━┷━┷━┻━┷━┷━┛";

   const char thin = "│";

   cont char thick = "┃";
   */
void Puzzle::print() {

    std::string top         ("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");

    std::string middleThin  ("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨");

    std::string middleThick ("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫");

    std::string bottom      ("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛");

    const char thin = '│';

    const char thick = '┃';

    std::cout << top << std::endl;
    for (int i = 0; i < 9; i++) {             
        for (int j = 0; j < 9; ++j) {
            std::cout << (j % 3 ? thin : thick);
            if (grid[i][j] == 0 ) 
                std::cout << "   ";
            else 
                std::cout << " " << grid[i][j] << " ";
        }
        std::cout << thick << std::endl;
        if (i == 2 || i == 5)
            std::cout << middleThick << std::endl;
        else if (i == 8)
            std::cout << bottom << std::endl;
        else 
            std::cout << middleThin << std::endl;
    }
}



#endif
