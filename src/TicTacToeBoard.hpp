#pragma once

#define BOARD_SIZE 3

// This is a class that handles board logic
// such as storage of positions and win detection

enum CellValue
{
    Nought,
    Cross,
    Empty,
    OffBoard
};

class TicTacToeBoard
{
public:
    TicTacToeBoard();
    CellValue getCell(int x, int y);
    void setCell(int x, int y, CellValue value);
    void clear();
    bool playerHasWon(CellValue playerValue);
    bool isDraw();

private:
    CellValue m_columns[BOARD_SIZE][BOARD_SIZE];
};