#include "Tetromino.h"
#include "GameBoard.h"
#include <gtest/gtest.h>

// ctrl+shift+p, C/C++: Edit Configurations (JSON), добавляем в includepath путь к папке include google test.

TEST(GameBoardTest, Constructor){
    GameBoard board(10, 20);
    ASSERT_EQ(board.getWidth(), 10);
    ASSERT_EQ(board.getHeight(), 20);
}

TEST(GameBoardTest, isCellOccupied){
    GameBoard board(10, 20);

    ASSERT_TRUE(board.isCellOccupied(0, 0));

    vector<vector<int>> boardState = board.getBoardState();
    boardState[0][0] = 1;
    board.setBoardState(boardState);

    ASSERT_FALSE(board.isCellOccupied(0, 0));
}

TEST(GameBoardTest, clearLines){
    GameBoard board(10, 20);

    vector<vector<int>> boardState = board.getBoardState();

    for (int i = 0; i < boardState[0].size(); i++){
        boardState[0][i] = 1;
    }
    board.setBoardState(boardState);
    ASSERT_EQ(board.clearLines(), 1);

    boardState = board.getBoardState();
    for (int i = 0; i < boardState[0].size(); i++){
        ASSERT_EQ(boardState[0][i], 0);
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < boardState[0].size(); j++){
            boardState[i][j] = 1;
        }
    }
    board.setBoardState(boardState);

    ASSERT_EQ(board.clearLines(), 2);
    boardState = board.getBoardState();

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < boardState[0].size(); j++){
            ASSERT_EQ(boardState[i][j], 0);
        }
    }
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}