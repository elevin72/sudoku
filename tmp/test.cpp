#include <iostream>
void getPuzzle(){

}
int main () {

    int grid[9][9];
   
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j) {
            grid[j][i] = j;
        }  
    }
        

    std::string top         ("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");

    std::string middleThin  ("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨");

    std::string middleThick ("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫");

    std::string bottom      ("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛");

    std::string thin  ("│");

    std::string thick ("┃");
    
    std::cout << "top " << top << std::endl;
    std::cout << "middlethin " << middleThin << std::endl;
    std::cout << "middlethick " << middleThick << std::endl;
    std::cout << "bottom " << bottom << std::endl;
    std::cout << "thin " << thin << std::endl;
    std::cout << "thick " << thick << std::endl;

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
