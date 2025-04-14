#include "Tetromino.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

void Tetromino::setCoordinate(){
    Coord figure;
    switch(this->Type){
        case I:
            figure.x1 = make_pair(0, 0);
            figure.y1 = make_pair(1, 0);
            figure.x2 = make_pair(2, 0);
            figure.y2 = make_pair(3, 0);
            this->coordinates = figure;
            break;
        case O:
            figure.x1 = make_pair(0, 0);
            figure.y1 = make_pair(1, 0);
            figure.x2 = make_pair(0, 1);
            figure.y2 = make_pair(1, 1);
            break;
        case J:
            figure.x1 = make_pair(0, 2);
            figure.y1 = make_pair(1, 2);
            figure.x2 = make_pair(1, 1);
            figure.y2 = make_pair(1, 0);
            break;
        case L:
            figure.x1 = make_pair(0, 0);
            figure.y1 = make_pair(0, 1);
            figure.x2 = make_pair(0, 2);
            figure.y2 = make_pair(1, 2);
            break;
        case T:
            figure.x1 = make_pair(0, 1);
            figure.y1 = make_pair(1, 1);
            figure.x2 = make_pair(1, 0);
            figure.y2 = make_pair(2, 1);
            break;
        default:
            cout << "Undefined type of figure" << endl;
            break;
    }
    this->coordinates = figure;
}

bool Tetromino::isValidPosition(int xOffset, int yOffset){
    return (xOffset < 10 && xOffset >= 0 && yOffset < 20 && yOffset >= 0);
}

//Исправить, добавить матрицу вращения
void Tetromino::rotate(){
    int centerX, centerY;
    switch (this->Type)
    {
    case I:
        centerX = 1;
        centerY = 1;
        break;
    case O:
        centerX = 0;
        centerY = 0;
        break;
    case J:
    case L:
    case T:
        centerX = 1;
        centerY = 1;
        break;
    default:
        cout << "Undefined type of figure" << endl;
        break;
    }

    auto rotate90 = [centerX, centerY](int x, int y){
        int newX = (y - centerY) + centerX;
        int newY = -(x - centerX) + centerY;
        return make_pair(newX, newY);
    };

    pair<int, int> oldX1 = this->coordinates.x1;
    pair<int, int> oldY1 = this->coordinates.y1;
    pair<int, int> oldX2 = this->coordinates.x2;
    pair<int, int> oldY2 = this->coordinates.y1;

    this->coordinates.x1 = rotate90(this->coordinates.x1.first, this->coordinates.x1.second);
    this->coordinates.y1 = rotate90(this->coordinates.y1.first, this->coordinates.y1.second);
    this->coordinates.x2 = rotate90(this->coordinates.x2.first, this->coordinates.x2.second);
    this->coordinates.y2 = rotate90(this->coordinates.y2.first, this->coordinates.y2.second);

    if (!isValidPosition(this->coordinates.x1.first, this->coordinates.y1.second) ||
        !isValidPosition(this->coordinates.x2.first, this->coordinates.y2.second)){
            this->coordinates.x1 = oldX1;
            this->coordinates.y1 = oldY1;
            this->coordinates.x2 = oldX2;
            this->coordinates.y2 = oldY2;
        }
}

void Tetromino::move(int dx, int dy){
    this->coordinates.x1 = make_pair(this->coordinates.x1.first + dx, this->coordinates.x1.second + dy);
    this->coordinates.y1 = make_pair(this->coordinates.y1.first + dx, this->coordinates.y1.second + dy);
    this->coordinates.x2 = make_pair(this->coordinates.x2.first + dx, this->coordinates.x2.second + dy);
    this->coordinates.y2 = make_pair(this->coordinates.y2.first + dx, this->coordinates.y2.second + dy);
}

Coord Tetromino::getCoordinates(){
    return this->coordinates;
}

bool Tetromino::checkForBorder(int width, int height){
    if (isValidPosition(this->coordinates.x1.first, this->coordinates.x1.second) &&
        isValidPosition(this->coordinates.y1.first, this->coordinates.y1.second) &&
        isValidPosition(this->coordinates.x2.first, this->coordinates.x2.second) &&
        isValidPosition(this->coordinates.y2.first, this->coordinates.y2.second)
    ){
        return true;
    }else{
        return false;
    }
}

