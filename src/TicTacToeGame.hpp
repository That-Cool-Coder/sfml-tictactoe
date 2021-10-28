#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <SFML/Graphics.hpp>
#include "shared.hpp"
#include "miniengine/miniengine.hpp"
#include "TicTacToeBoard.hpp"
#include "NoughtGraphic.hpp"
#include "CrossGraphic.hpp"

enum GamePhase
{
    StartScreen,
    Playing,
    ShowingWinner
};

class TicTacToeGame : public miniengine::Scene
{
private:
    // Drawing stuff
    // -------------
    const sf::Color m_backgroundColor = sf::Color(20, 20, 20);
    const sf::Color m_cellBorderColor = sf::Color(70, 70, 70);
    const sf::Color m_textColor = sf::Color::White;
    const int m_topBarHeight = 60;
    const int m_bottomBarHeight = 30;
    const int m_windowPadding = 20;
    const float m_cellPaddingProportion = 0.2; // proportion of cell to fill
    const float m_cellBorderWidthProportion = 0.025; // proportion of window width to use
    std::vector<std::reference_wrapper<sf::Text>> m_textEntities;
    int m_boardSize;
    int m_cellSize;
    int m_boardLeft;
    int m_boardTop;
    std::shared_ptr<sf::Text> m_headingText;

    void setup();
    void update();
    void handleEvent(sf::Event& event);

    void loadFont();
    void createText();
    void calcBoardSize();
    void drawCellBorders();
    void drawCells();
    void updateText();
    void setCellContents(sf::Event event);

    // Game logic stuff
    // ----------------
    TicTacToeBoard m_board;
    CellValue m_crntPlayer;
    GamePhase m_gamePhase = Playing;
    miniengine::Timer m_showWinnerTimer = miniengine::Timer(sf::seconds(3));
    Winner m_winner = Winner::GameNotFinished;

    void createBoard();
};