#ifndef SUDOOKU_H
#define SUDOKU_H
#include <string>
#include <iostream>

class Sudoku {
    public:
        bool hc[9], vc[9], bc[9]; // for storing data about numbers in rects h,v and b
        int grid[9][9]/* = {{2,1,0,9,0,3,0,0,0},{0,0,0,0,7,1,8,0,0},{0,0,0,0,0,2,0,0,6},
                          {0,0,7,0,0,0,0,1,3},{6,0,0,0,0,0,0,5,7},{0,0,1,0,0,0,0,0,0},
                          {0,6,2,0,5,0,0,0,0},{0,0,0,6,0,0,4,0,0},{3,0,4,0,0,0,0,0,0}}; */
        Sudoku();
        void inputByRow();
        void print(); 
        bool solveR(int index);
    private:
        std::string top, middleThin, middleThick, bottom, thin, thick;
        bool isValid(int index, int i);
        void horizontalScan(int index);
        void verticalScan(int index);
        void boxScan(int index);
        int firstBoxIndex(int index);
        int nextInBox(int index);
        void resetCanidateArrays();
};

Sudoku::Sudoku() {
    top =         ("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");
    middleThin =  ("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨");
    middleThick = ("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫");
    bottom     =  ("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛");
    thin       =  ("│");
    thick      =  ("┃");
    resetCanidateArrays();
    inputByRow();
    print();
    char trash;
    std::cout << "ok?\n";
    std::cin >> trash; // can make this a loop to improve inputs
}

bool Sudoku::solveR(int index) {
    while (grid[0][index] != 0 )
        index++;
    if (index > 80)
        return true;
    for (int i = 0; i < 9; ++i) {
        if (isValid(index, i)) {
            grid[0][index] = i+1;
            if (solveR(index+1))
                return true;
        }
    }
    grid[0][index] = 0;
    return false;
}

void Sudoku::resetCanidateArrays() {
    for (int i = 0; i < 9; ++i) {
        hc[i] = vc[i] = bc[i] = true;
    }
}

bool Sudoku::isValid(int index, int i) {
    resetCanidateArrays();
    horizontalScan(index);
    verticalScan(index);
    boxScan(index);
    if (hc[i] && vc[i] && bc[i])
        return true;
    else 
        return false;
}

void Sudoku::horizontalScan(int index) {
    int end, val, first = index - (index % 9);
    end = first + 9;
    for (; first < end; ++first) {
        val = grid[0][first];
        if (val != 0) 
            hc[val-1] = false;
    }
}

void Sudoku::verticalScan(int index) {
    int val, first = index - (9 * (index / 9)); // integer division is not real division
    for (; first < 81; first+=9) {
        val = grid[0][first];
        if (val != 0)
            vc[val-1] = false;
    }
}

void Sudoku::boxScan(int index) {
    int end, val, first = firstBoxIndex(index);
    end = first + 21;
    for (; first < end; first = nextInBox(first)) {
        val = grid[0][first];
        if (val != 0)
            bc[val-1] = false;
    }
}

int Sudoku::firstBoxIndex(int index) {
    int boxIndex, a = index/9, b = index%9;
    // figure out which box we're in
    if      (a < 3) a = 0;
    else if (a < 6) a = 1;
    else/*(a < 9)*/ a = 2;
    if      (b < 3) b = 0;
    else if (b < 6) b = 1;
    else/*(b < 9)*/ b = 2;
    boxIndex = (a*3)+b;
    // return value is first index of box. break not needed since returning 
    switch(boxIndex) {         
        case 0:
            return 0; 
        case 1:
            return 3; 
        case 2:
            return 6 ; 
        case 3:
            return 27; 
        case 4:
            return 30; 
        case 5:
            return 33; 
        case 6:
            return 54; 
        case 7:
            return 57; 
        case 8:
            return 60; 
        default:
            return -1; // so compiler shuts up
    }
}

int Sudoku::nextInBox(int i) {
    return ( ( (i+1) % 3 ) ? i+7 : ++i);
    /*if ((i + 1) % 3 != 0)
        return ++i;
    else
        return i+7; */
}

void Sudoku::inputByRow() {
    int n;
    bool inRange;
    std::cout << "Enter numbers of sudoku puzzle. 0 denotes empty space." << std::endl;
    for (int i = 0; i < 9; ++i) {
        do {
            std:: cout << "Enter row " << i+1 << ": ";
            if (i == 0)
                std::cout << top << std::endl;
            else if (i == 3 || i == 6)
                std::cout << middleThick << std::endl;
            else 
                std::cout << middleThin << std::endl;
            std::cout << "             ";
            inRange = true;
            for (int j = 0; j < 9; ++j){
                std::cin >> n;
                if (n < 0 || n > 9)
                    inRange = false;
                grid[i][j] = n;
            }
            if (!inRange)
                std::cout << "Numbers not in range. Try again." << std::endl;
        } while (!inRange);
    }
    std::cout << "             " << bottom << std::endl;
}

void Sudoku::print() {
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
