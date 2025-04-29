#include "GameSession.h"
#include "GameBoard.h"
#include "Player.h"
#include "Tetromino.h"
#include "TetrominoGenerator.h"

int main(){
    //GameSession game;
    string name;
    int option;

    cout << "Enter the nickname: ";
    getline(cin, name);

    cout << name << endl;
    GameSession game(name);
    game.setBoard();

    do{
        cout << "Enter the 0 for exit, 1 to continue: ";
        cin >> option;
        switch (option){
            case 0:
                system("cls");
                cout << "Bye!" << endl;
                break;
            default:
                game.setCurrentTetromino();
                game.placeTetromino();
                game.showBoard();
                game.move();
        }
    }while (option != 0);
    return 0;
}
