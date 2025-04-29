#include "GameBoard.h"
#include "Tetromino.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Свободна ли позиция
 */
bool GameBoard::isCellOccupied(int x, int y){
    if (this->board[x][y] == 0){
        return true;
    }else{
        return false;
    }
}

/**
 * Удаление полных строк
 */
int GameBoard::clearLines(){
    vector<int> lines; /// {{}, {}, {}}
    for (int i = 0; i < this->board.size(); i++){
        int flag=1;
        for (int j = 0; j < this->board[0].size(); j++){
            if (this->board[i][j] == 0){
                flag = 0;
                break;
            }
        }
        if (flag){
            lines.push_back(i);
        }
    }

    if (!lines.empty()){
        for (int i=0; i < lines.size(); i++){
            this->board.erase(this->board.begin() + i);
            this->board.insert(this->board.begin(), vector<int>(10));
        }
    }
    
    return static_cast<int>(lines.size());
}

/**
 * Можно ли разместить фигуру(есть ли на неё место?)
 */
bool GameBoard::canPlaceTetromino(Tetromino &tetromino){
    Coord coordinates = tetromino.getCoordinates();
    
    if (isCellOccupied(coordinates.x1.first, coordinates.x1.second) &&
    isCellOccupied(coordinates.x2.first, coordinates.x2.second) &&
    isCellOccupied(coordinates.y1.first, coordinates.y1.second) &&
    isCellOccupied(coordinates.y2.first, coordinates.y2.second)){
        return true;
    }else{
        return false;
    }
}

/**
 * Сброс доски
 */
void GameBoard::reset(){;
    vector<vector<int>> board(10, vector<int>(10));
    this->board = board;
}

/**
 * Вывод доски на экран
 */
void GameBoard::printBoard(){
    for(int i = 0; i < this->board.size(); i++){
        for (int j = 0; j < this->board[0].size(); j++){
            cout << this->board[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Получить высоту доски
 */
int GameBoard::getHeight(){
    return this->height;
}

/**
 * Получить ширину доски
 */
int GameBoard::getWidth(){
    return this->width;
}

/**
 * Получить текущую доску
 */
vector<vector<int>> GameBoard::getBoardState(){
    return this->board;
}

/**
 * Размещение фигуры
 */
void GameBoard::placeTetromino(Tetromino &tetromino){
    if (canPlaceTetromino(tetromino) && tetromino.checkForBorder(this->width, this->height)){
        Coord coordinates = tetromino.getCoordinates();
        this->board[coordinates.x1.first][coordinates.x1.second] = 1;
        this->board[coordinates.y1.first][coordinates.y1.second] = 1;
        this->board[coordinates.x2.first][coordinates.x2.second] = 1;
        this->board[coordinates.y2.first][coordinates.y2.second] = 1;
    }
}

/**
 * Обновление доски
 */
void GameBoard::setBoardState(vector<vector<int>> boardState){
    this->board = boardState;
}

