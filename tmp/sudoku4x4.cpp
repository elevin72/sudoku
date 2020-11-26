#include <iostream>
/*
 * 1 2 3 4
 * 4 3 2 1
 * 2 4 1 3
 * 3 1 4 2
 *
 *
 *
 */
int arr[4][4] = {{0,2,3,4}, {4,3,2,1}, {2,4,1,3}, {3,1,4,2}};
int solveSquare(int index){
    if (index != 0)
        return index;
    bool comp[4];
    for (int i = 0; i < 4; ++i)
        comp[i] = false;
    // go over horizontal
    // assume square is start of rectangle!! -- index = start;
    for (int i = 0; i < 4; ++i){
        //horizontal
        if (arr[index/4][i] != 0)
            comp[i] = true;
        // vertical
        if (arr[i][index%4])
            comp[i] = true;
        //box -- hardest one -- should get indexes 0,1,4,5 or
        //(0,0) (0,1) (1,0) (1,1)
        if (arr[][])
    }

}
// return first index of box, based on any index.
// tested!!
int firstBoxIndex(int index) {
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
/* After staring at this for a long time, I can't find a hard pattern
 * Lets just decrement till the first multiple of 3 and then subtract 9 or 18
 * until finding 0,3 6,27,30, 54, 57 or 60. It's messy, but it identifies the
 * start of a box
 * How to increment through a box: if next number is a multiple of 3, then add 6.
 * if it is 20, 23,26,47,50,74,77,80 then say we're at end.
 * subtract 20 to get back to beginning
 *
 * 0 1 2, 9 10 11, 18 19 20
 * 
 * 3 4 5, 12 13 14, 21 22 23
 * 
 * 6 7 8, 15 16 17, 24 25 26
 * 
 * 27 28 29, 36 37 38, 45 46 47
 *
 * 30 31 32, 39 40 41, 48 49 50
 *
 * 54 55 56, 63 64 65, 72 73 74
 *
 * 57 58 58, 66 67 68, 75 76 77
 *
 * 60 61 62, 69 70 71, 78 79 80
 *
 *
 * 0  1  2  3  4  5  6  7  8
 * 9  10 11 12 13 14 15 16 17
 * 18 19 20 21 22 23 24 25 26
 * 27 28 29 30 31 32 33 34 35
 * 36 37 38 39 40 41 42 43 44 
 * 45 46 47 48 49 50 51 52 53
 * 54 55 56 57 58 59 60 61 62
 * 63 64 65 66 67 68 69 70 71
 * 72 73 74 75 76 77 78 79 80
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
 
int ()

int main() {
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j)
            if (arr[i][j] == 0)
                std::cout << "   ";
            else 
                std::cout << " " << arr[i][j] << " ";
        std::cout << std::endl;
    }
}
