#include "Tetromino.h"

class TetrominoGenerator{
    private:
        int Tetromino_index = 0;
        void FisherSort();
        vector<Type_of_figure> bag;
    public:
        Tetromino getRandomTetromino();
        void Tetromino_index_increment();
};