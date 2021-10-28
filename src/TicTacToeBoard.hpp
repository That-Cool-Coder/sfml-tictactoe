#pragma once

#define BOARD_SIZE 3

// This is a class that handles board logic
// such as storage of positions and win detection

enum class CellValue
{
    Nought,
    Cross,
    Empty,
    OffBoard
};

enum class Winner
{
    Nought,
    Cross,
    Draw,
    GameNotFinished
};

class TicTacToeBoard
{
public:
    TicTacToeBoard();
    CellValue getCell(int x, int y);
    void setCell(int x, int y, CellValue value);
    void clear();
    Winner findWinner();

private:
    bool playerHasWon(CellValue playerValue);
    bool isDraw();

    CellValue m_columns[BOARD_SIZE][BOARD_SIZE];
};