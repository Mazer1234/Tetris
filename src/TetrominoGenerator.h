#pragma once
#include "Tetromino.h"

class TetrominoGenerator{
    private:
        int Tetromino_index = 0;
        void FisherSort();
        vector<Type_of_figure> bag;
        void Tetromino_index_increment();
    public:
        Tetromino getRandomTetromino();
};