#include "Tetromino.h"


class GameBoard{
    private:
        vector<vector<int>> board;
    public:
        GameBoard(int width, int height): board(width, vector<int>(height)) {}
        bool isCellOccupied(int x, int y);
        void clearLines();
        bool canPlaceTetromino(const Tetromino &tetromino);

};

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
void GameBoard::clearLines(){
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
    
}

bool GameBoard::canPlaceTetromino(const Tetromino &tetromino){
    
}
