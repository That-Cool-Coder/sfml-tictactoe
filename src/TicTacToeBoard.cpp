#include "TicTacToeBoard.hpp"

TicTacToeBoard::TicTacToeBoard()
{
    clear();
}

CellValue TicTacToeBoard::getCell(int x, int y)
{
    if (x < BOARD_SIZE && y < BOARD_SIZE)
    {
        return m_columns[x][y];
    }
    else
    {
        return OffBoard;
    }
}

void TicTacToeBoard::setCell(int x, int y, CellValue value)
{
    if (x < BOARD_SIZE && y < BOARD_SIZE)
    {
        m_columns[x][y] = value;
    }
}

void TicTacToeBoard::clear()
{
    for (int x = 0; x < BOARD_SIZE; x ++)
    {
        for (int y = 0; y < BOARD_SIZE; y ++)
        {
            setCell(x, y, Empty);
        }
    }
}

bool TicTacToeBoard::playerHasWon(CellValue playerValue)
{
    /* Check different ways that the game could have been won (rows, cols, diagonals).
    If you find a match, return immediately.
    */

    // First check if any of the rows are all full of playerValue
    for (int y = 0; y < BOARD_SIZE; y ++)
    {
        bool rowWon = true; // whether all the cells in the row are playerValue
        for (int x = 0; x < BOARD_SIZE; x ++)
        {
            if (getCell(x, y) != playerValue)
            {
                rowWon = false;
                break;
            }
        }
        if (rowWon) return true;
    }

    // Then check if any of the columns are full of playerValue
    for (int x = 0; x < BOARD_SIZE; x ++)
    {
        bool colWon = true; // whether all the cells in the col are playerValue
        for (int y = 0; y < BOARD_SIZE; y ++)
        {
            if (getCell(x, y) != playerValue)
            {
                colWon = false;
                break;
            }
        }
        if (colWon) return true;
    }

    // Check top-left to bottom-right diagonal
    bool diagonalWon = true; // whether all the cells in the diagonal are playerValue
    for (int rowAndCol = 0; rowAndCol < BOARD_SIZE; rowAndCol ++)
    {
        if (getCell(rowAndCol, rowAndCol) != playerValue)
        {
            diagonalWon = false;
            break;
        }
    }
    if (diagonalWon) return true;

    // Check bottom-right to top-left diagonal
    diagonalWon = true; // whether all the cells in the diagonal are playerValue
    for (int rowAndCol = 0; rowAndCol < BOARD_SIZE; rowAndCol ++)
    {
        if (getCell(rowAndCol, BOARD_SIZE - rowAndCol - 1) != playerValue)
        {
            diagonalWon = false;
            break;
        }
    }
    if (diagonalWon) return true;

    // If nothing has been found then the player has not won
    return false;
}

bool TicTacToeBoard::isDraw()
{
    /* A draw is defined when all of the cells in the board have been filled.
    We assume that it's a draw and then check to see if any spaces are vacant.
    If they are vacant, then it's not a draw
    */

    for (int row = 0; row < BOARD_SIZE; row ++)
    {
        for (int col = 0; col < BOARD_SIZE; col ++)
        {
            if (getCell(col, row) == Empty) return false;
        }
    }
    return true;
}