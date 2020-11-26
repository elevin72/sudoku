#ifndef SUDOOKU_H
#define SUDOKU_H
#include <string>
#include <iostream>
/* class Rectangle; */
/* class h_rect; */
/* class v_rect; */
/* class b_rect; */

class Sudoku {
    public:
        /* friend class Rectangle; */
        bool canidates[9], hc[9], vc[9], bc[9]; // for storing data about numbers in rects h,v and b
        /* int grid[9][9]; // written backwards. grid[y][x] */
        int grid[9][9] = { {7,4,5,0,9,0,0,0,0}, {0,3,2,1,5,0,0,4,6}, {0,0,0,2,8,0,5,0,3},
                       {2,0,0,0,0,0,0,6,0}, {9,8,0,6,0,0,3,5,1}, {0,0,0,5,4,0,2,0,7},
                       {3,0,8,0,0,0,0,0,2}, {0,2,0,7,6,0,0,1,0}, {0,6,0,9,0,8,0,3,4}};
        Sudoku();
        void solve();
        /* void solveSquare(int index); */
        void singleCanidate(int index);
        bool isSolved();
        void horizontalScan(int index);
        void verticalScan(int index);
        void boxScan(int index);
        int firstBoxIndex(int index);
        int nextInBox(int index);
        void resetCanidateArrays();
        void inputByRow();
        void print(); 

       /* *h_rect getRectH(int x, int y); */
        /* *v_rect getRectV(int x, int y); */
        /* *b_rect getRectB(int x, int y); */
        /* class Rectangle; // and define it elsewhere? */
        // something like an iterator
        /* class Rectangle { */
        /*     int first, value, index, x, y; */
        /*     bool comparison[9]; */
        /*     Rectangle(Sudoku *_sudoku, int _x, int _y); */
        /*     virtual int operator++() = 0; */
        /*     virtual int operator--() = 0; */
        /*     virtual int& operator[](int i) = 0; */
        /*     virtual int getRect(int x, int y) = 0; */
        /*     bool isSolved(); */
        /*     void resetView(); */
        /*     void resetComparison(); */

        /* }; */

    /* private: */
        std::string top, middleThin, middleThick, bottom, thin, thick;
        
};

Sudoku::Sudoku() {
    top =         ("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");
    middleThin =  ("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨");
    middleThick = ("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫");
    bottom     =  ("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛");
    thin       =  ("│");
    thick      =  ("┃");
    // maybe inputByRow() here?
    inputByRow(); 
    print();
    std::cout <<"ok? \n";
    char garbage;
    std::cin >> garbage;
    resetCanidateArrays();
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
        if (count++ == 1000) {
            std::cout << "1000 cycles is too many.\n";
            break;
        }
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


void Sudoku::singleCanidate(int index) {
    horizontalScan(index);
    verticalScan(index);
    boxScan(index);
    for (int i = 0; i < 9; ++i){
        canidates[i] = ( hc[i] && vc[i] && bc[i] );
    }
    bool isOnly = true;
    int c = 0; // better name ??
    for (int i = 0; i < 9; ++i){
        /* std::cout << "Log: in SingleCanidate\n"; */
        if (canidates[i]) {
            if (isOnly){
                c = i+1;
                isOnly = false;
            }
            else { // !isOnly and hence not enough information
                c = 0;
                break; // and c will stay = 0
            }
        }
    }
    resetCanidateArrays();
    grid[0][index] = c;;
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
    for (; first < i + 9; ++first) { // is this ok? It's definitely ugly
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
    for (; first < i + 21 /*??*/; first = nextInBox(first)) { // loop isnt ending
        /* std::cout << "Log: b scan\n"; */
        int val = grid[0][first];
        if (val != 0)
            bc[val-1] = false;
    }
}


int Sudoku::firstBoxIndex(int index) {
    if (index < 0 || index > 80)
        //throw something
        std::cout << "Exception!\n";
    int boxIndex, a = index/9, b = index%9;
    if (a < 3)
        a = 0;
    else if (a < 6)
        a = 1;
    else //if (a < 9)
        a = 2;
    if (b < 3)
        b = 0;
    else if (b < 6)
        b = 1;
    else //if (b < 9)
        b = 2;

    boxIndex = (a*3)+b;
    switch(boxIndex) { // return value is first index of box. break not needed since returning 
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
    }
}

int Sudoku::nextInBox(int i) {
    if ((i + 1) % 3 != 0)
        return ++i;
    else
        return i+7; //!!
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

#endif
