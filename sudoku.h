#ifndef SUDOOKU_H
#define SUDOKU_H
#include <string>
#include <iostream>

class Sudoku {
    public:
        bool canidates[9], hc[9], vc[9], bc[9]; // for storing data about numbers in rects h,v and b
        int grid[9][9]; // written backwards. grid[y][x]
        Sudoku();
        void solve();
        bool isSolved();
        void inputByRow();
        void print(); 
        /* void solveSquare(int index); */
    private:
        std::string top, middleThin, middleThick, bottom, thin, thick;
        void singleCanidate(int index);
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
}

void Sudoku::solve() {
    int count = 0;
    while (isSolved() == false) {
        print();
        std::cout << "cycle #" << count+1 << "\n";
        for (int i = 0; i < 81; ++i) {
            if (grid[0][i] == 0) {
                singleCanidate(i);
            }
        }
        if (count++ == 100) {
            std::cout << "100 cycles is too many.\n";
            break;
        }
    }
}

void Sudoku::singleCanidate(int index) {
    horizontalScan(index);
    verticalScan(index);
    boxScan(index);
    for (int i = 0; i < 9; ++i){
        canidates[i] = ( hc[i] && vc[i] && bc[i] );
    }
    bool isOnly = true;
    int n = 0;
    for (int i = 0; i < 9; ++i){
        /* std::cout << "Log: in SingleCanidate\n"; */
        if (canidates[i]) {
            if (isOnly){
                n = i+1;
                isOnly = false;
            }
            else { // !isOnly and hence not enough information
                n = 0;
                break; // and n will stay = 0
            }
        }
    }
    resetCanidateArrays();
    grid[0][index] = n;
}

bool Sudoku::isSolved() {
    for (int i = 0; i < 81; ++i) {
        /* std::cout << "Log: checking if solved\n"; */
        if (grid[0][i] == 0)
            return false;
    }
    std::cout << "Solved!\n";
    return true;
}

void Sudoku::horizontalScan(int index) {
    int i, first = index - (index % 9);
    i = first;
    for (; first < i + 9; ++first) {
        /* std::cout << "Log: h scan\n"; */
        int val = grid[0][first];
        if (val != 0) 
            hc[val-1] = false;
    }
}

void Sudoku::verticalScan(int index) {
    int first = index - (9 * (index / 9)); // integer division is not real division
    for (; first < 81; first+=9) {
        /* std::cout << "Log: v scan\n"; */
        int val = grid[0][first];
        if (val != 0)
            vc[val-1] = false;
    }
}

void Sudoku::boxScan(int index) {
    int i,first = firstBoxIndex(index);
    i = first;
    for (; first < i + 21; first = nextInBox(first)) {
        /* std::cout << "Log: b scan\n"; */
        int val = grid[0][first];
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
    if ((i + 1) % 3 != 0)
        return ++i;
    else
        return i+7;
}

void Sudoku::resetCanidateArrays() {
    for (int i = 0; i < 9; ++i) {
        hc[i] = vc[i] = bc[i] = true;
    }
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

// keep this function around, it could be useful if employing other strategies
/* void Sudoku::solveSquare(int index){ */
/*     int val = grid[0][index]; // for debugging */
/*     if (grid[0][index] == 0) { */
/*         singleCanidate(index); */
/*     } */
/*     // different methods to employ: */
/*     // 1. Single canidate. check and see that no other number can go there */
/*     // 2. Scan boxwise. where you eliminate rows and columns for a certain number */
/*     // in a particular box, and are left with one option. Instead of asking What */
/*     // number can go here, asking Where can I put this number? */
/*     // 3. Deduce that although the particular placement is unknown, it's enough info */
/*     // to figure out something else. */
/*     // 4. More esoteric stuff called naked pairs, and x wings */
/*     // stuff with rectangles */
/*     // This is where the magic happens */
/*     // check all three rectangles and see if we can find 8 numbers */
/* } */

#endif
