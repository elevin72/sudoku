#include "grid.h"

class Rectangle {
    public: 
        Puzzle *grid;
        const int first;
        int current, currentindex;
        bool comparison[9];
        Rectangle(Puzzle *_grid, int _first);
        virtual int next() = 0;
        virtual int prev() = 0;
        virtual int& operator[](int i) = 0;
        bool issolved();
        void resetcomparison();
        void resetview();

};
