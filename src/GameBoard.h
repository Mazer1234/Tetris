#include "Tetromino.h"
#include <vector>
#include <iostream>

using namespace std;

class GameBoard{
    private:
        vector<vector<int>> board;
        int height;
        int width;
    public:
        GameBoard(int wd, int hg): board(wd, vector<int>(hg)), height(hg), width(wd) {}
        int clearLines();
        bool isCellOccupied(int x, int y);
        bool canPlaceTetromino(Tetromino &tetromino);
        void reset();
        void printBoard();
        int getWidth();
        int getHeight();
        vector<vector<int>> getBoardState();
        void placeTetromino(Tetromino &tetromino);
        void setBoardState(vector<vector<int>> boardState);
};

