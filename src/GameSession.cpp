#include "GameSession.h"
#include <iostream>


void GameSession::setPlayer(string name){
    this->player = Player(name);
}

void GameSession::setBoard(){
    GameBoard board(10, 20);
    this->board = board;
}

/**
 * Получение текущей фигуры
*/
void GameSession::setCurrentTetromino(){
    this->currentTetromino = this->tetrominoGenerator.getRandomTetromino();
}

/**
 *  Показать текущее состояние доски
 * */ 
void GameSession::showBoard(){
    this->board.printBoard();
}

/**
 * Создать новую фигуру и расположить её на доске
 */
void GameSession::placeTetromino(){
    setCurrentTetromino();
    this->board.placeTetromino(currentTetromino);
}

//Доделывать здесь ошибка
/**
 * Смещение всех фигур вниз на одну клетку
 */
void GameSession::move(){
    this->board.clearLines();
    try{
        this->currentTetromino.move(1, 0);
        this->board.placeTetromino(currentTetromino);
    }catch(...){
        setCurrentTetromino();
    }
}