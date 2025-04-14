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
};