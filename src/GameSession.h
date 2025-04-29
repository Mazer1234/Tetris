#include "GameBoard.h"
#include "Tetromino.h"
#include "Player.h"
#include "TetrominoGenerator.h"

class GameSession{
    private:
        Player player;
        GameBoard board;
        TetrominoGenerator tetrominoGenerator;
        Tetromino currentTetromino;
        Tetromino nextTetromino;
        int score;
        bool isGameOver;
    public:
        void setPlayer(string player);
        void setBoard();
        void setCurrentTetromino();
        void showBoard();
        GameSession(string name): player(name), board(10, 20), tetrominoGenerator(), currentTetromino(I), nextTetromino(J){}
        void placeTetromino();
        void move();
};