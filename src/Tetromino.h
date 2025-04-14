#pragma once
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


enum Type_of_figure{
    I, O, J, L, T,
    Type_first = I,
    Type_last = T
};

struct Coord{
    pair<int, int> x1;
    pair<int, int> y1;
    pair<int, int> x2;
    pair<int, int> y2;
};

class Tetromino{
    private:
        Type_of_figure Type;
        int Rangle;
        void setCoordinate();
        Coord coordinates;
    public:
        void rotate();
        void move(int dx, int dy);
        bool isValidPosition(int xOffset, int yOffset);
        Coord getCoordinates();
        Tetromino(Type_of_figure t): Type(t){}
        bool checkForBorder(int width, int height);
};

