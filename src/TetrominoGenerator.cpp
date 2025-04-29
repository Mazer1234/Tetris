#include "TetrominoGenerator.h"
#include <random>

/**
 * Сортировка фишера(Перестановка фигур в мешке в случайном порядке)
 */
void TetrominoGenerator::FisherSort(){

    for (int type = Type_first; type <= Type_last; type++){
        this->bag.push_back(static_cast<Type_of_figure>(type));
    }

    random_device rd; // создание генератора случайных чисел
    mt19937 gen(rd()); // инициализация генератора случайных чисел, скобки нужны так как это не число

    for (int i = this->bag.size() - 1; i > 0; i--){
        uniform_int_distribution<> distrib(0, i); // Задание диапазона случайных чисел
        int j = distrib(gen);
        Type_of_figure temp = bag[i];
        this->bag[i] = this->bag[j];
        this->bag[j] = temp;        
    }
}

/**
 * Получение случайной фигуры из мешка(В нашем случае первой фигуры)
 * После того как мешок закончится, сортировка фишера обновит его
 */
Tetromino TetrominoGenerator::getRandomTetromino(){
    if (this->bag.empty() || this->Tetromino_index > this->bag.size()-1){
        FisherSort();
    }
    
    Tetromino_index_increment();
    return this->bag[this->Tetromino_index]; // Там где вызывается надо увеличивать индекс
}

/**
 * Увеличение индекса фигур для мешка
 */
void TetrominoGenerator::Tetromino_index_increment(){
    if (this->Tetromino_index+1 < this->bag.size()) this->Tetromino_index ++;
    else if (this->Tetromino_index+1 == this->bag.size()) this->Tetromino_index = 0;
} 