#include <iostream>
#include <iterator>
void getPuzzle(){
    int n;
    bool inRange;
    std::cout << "Enter numbers of sudoku puzzle. 0 denotes empty space." << std::endl;
    for (int i = 0; i < 9; ++i) {
        do {
            std:: cout << "Enter row " << i+1 << ": ";
            if (i == 0)
                std::cout << top << std::endl;
            else if (i == 2 || i == 5)
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

int main () {
    std::string top         ("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");

    std::string middleThin  ("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨");

    std::string middleThick ("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫");

    std::string bottom      ("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛");

    int grid[9][9];
    int n;
    bool inRange;
    std::cout << "Enter numbers of sudoku puzzle. 0 denotes empty space." << std::endl;
    for (int i = 0; i < 9; ++i) {
        /* std:: cout << "Enter row " << i+1 << ": "; */
        /* if (i == 0) */
        /*     std::cout << top << std::endl; */
        /* else if (i == 2 || i == 5) */
        /*     std::cout << middleThick << std::endl; */
        /* else */ 
        /*     std::cout << middleThin << std::endl; */
        /* std::cout << "             "; */
        do {
            std:: cout << "Enter row " << i+1 << ": ";
            if (i == 0)
                std::cout << top << std::endl;
            else if (i == 2 || i == 5)
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
   
   /*
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j) {
            grid[j][i] = j;
        }  
    }
    */
        


    std::string thin  ("│");

    std::string thick ("┃");
    
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
    return 0;

}
