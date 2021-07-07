#pragma once
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TicTacToeBoard.hpp"
#include "NoughtGraphic.hpp"
#include "CrossGraphic.hpp"

enum GamePhase
{
    StartScreen,
    Playing,
    ShowingWinner
};

class TicTacToeGame
{
public:
    TicTacToeGame();
    TicTacToeGame(int width, int height);
    void mainLoop();
    void startNewGame();

private:
    // Drawing stuff
    // -------------
    const sf::Color m_backgroundColor = sf::Color(20, 20, 20);
    const sf::Color m_cellBorderColor = sf::Color(70, 70, 70);
    const int m_topBarHeight = 50;
    const int m_bottomBarHeight = 30;
    const int m_windowPadding = 20;
    const float m_cellPaddingProportion = 0.2; // proportion of cell to fill
    const float m_cellBorderWidthProportion = 0.05; // proportion of window width to use
    int m_width = 400;
    int m_height = 450;
    int m_boardSize;
    int m_cellSize;
    int m_boardLeft;
    int m_boardTop;
    sf::RenderWindow m_window;

    void calcBoardSize();
    void createWindow();
    void createBoard();
    void drawCellBorders();
    void drawCells();
    void setCellContents(sf::Event event);

    // Game logic stuff
    // ----------------
    TicTacToeBoard m_board;
    CellValue m_crntPlayer;
    GamePhase m_gamePhase = Playing;
};