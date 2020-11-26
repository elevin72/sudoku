#include <iostream>
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

int main () {
    int n;
    do {
        std::cin >> n;
        std ::cout << firstBoxIndex(n);
    } while(true);
}
