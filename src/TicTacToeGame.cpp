#include "TicTacToeGame.hpp"

TicTacToeGame::TicTacToeGame()
{
    loadFont();
    createWindow();
    createBoard();
    createText();
}

TicTacToeGame::TicTacToeGame(int width, int height)
{
    m_width = width;
    m_height = height;
    createWindow();
    createBoard();
    createText();
}

void TicTacToeGame::loadFont()
{
    if (! m_font.loadFromFile(m_fontFileName))
    {
        std::cout << "Could not load font from file " +
            m_fontFileName + "\n";
        std::cout << "The program will probably not work properly\n";
    }
}

void TicTacToeGame::createText()
{
    m_playerPrompt.setFont(m_font);
    m_playerPrompt.setCharacterSize(m_topBarHeight - 15);
    m_playerPrompt.setFillColor(m_textColor);
    m_textEntities.push_back(std::ref(m_playerPrompt));
}

void TicTacToeGame::createWindow()
{
    m_window.create(sf::VideoMode(m_width, m_height), "Tic Tac Toe");
}

void TicTacToeGame::createBoard()
{
    m_board = TicTacToeBoard();
}

void TicTacToeGame::mainLoop()
{
    startNewGame();
    while (m_window.isOpen())
    {
        calcBoardSize();
        m_window.clear(m_backgroundColor);

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) m_window.close();
            // catch the resize events
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                m_width = event.size.width;
                m_height = event.size.height;
                sf::FloatRect visibleArea(0, 0, m_width,  m_height);
                m_window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                switch (m_gamePhase)
                {
                case Playing:
                    setCellContents(event);
                    break;
                }
            }
        }
        switch (m_gamePhase)
        {
        case Playing:
            drawCellBorders();
            drawCells();
            updateText();
            drawText();
            break;
        case ShowingWinner:
            drawCellBorders();
            drawCells();
            updateText();
            drawText();
            break;
        }
        m_window.display();
    }
}

void TicTacToeGame::startNewGame()
{
    m_board.clear();
    m_crntPlayer = Cross; // todo: set this randomly
}

void TicTacToeGame::updateText()
{
    switch (m_crntPlayer)
    {
    case Cross:
        m_playerPrompt.setString("Player 1 turn");
        break;
    case Nought:
        m_playerPrompt.setString("Player 2 turn");
        break;
    }
    centerAlignText(m_playerPrompt);
    m_playerPrompt.setPosition(m_width / 2, m_topBarHeight / 2);
}

void TicTacToeGame::centerAlignText(sf::Text &text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);
}

void TicTacToeGame::drawText()
{
    for (auto text : m_textEntities)
    {
        m_window.draw(text);
    }
}

void TicTacToeGame::calcBoardSize()
{
    int availableHeight = m_height - m_topBarHeight - m_bottomBarHeight;
    m_boardSize = std::min(availableHeight, m_width) - m_windowPadding * 2;
    m_cellSize = m_boardSize / 3;
    m_boardLeft = (m_width - m_boardSize) / 2;
    m_boardTop = (m_height - m_boardSize) / 2;
}

void TicTacToeGame::drawCellBorders()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(m_cellBorderColor);
    int cellBorderWidth = m_cellBorderWidthProportion * m_boardSize;
    rectangle.setSize(sf::Vector2f(m_boardSize, cellBorderWidth));
    rectangle.setOrigin(m_boardSize / 2, cellBorderWidth / 2);

    // Do the horizontal borders
    for (int y = 1; y < BOARD_SIZE; y ++)
    {
        rectangle.setPosition(m_boardLeft + m_boardSize / 2,
            m_boardTop + y * m_cellSize);
        m_window.draw(rectangle);
    }

    // Do the vertical borders
    rectangle.setRotation(90);
    for (int x = 1; x < BOARD_SIZE; x ++)
    {
        rectangle.setPosition(m_boardLeft + x * m_cellSize,
            m_boardTop + m_boardSize / 2);
        m_window.draw(rectangle);
    }
}

void TicTacToeGame::drawCells()
{
    int cellPadding = m_cellPaddingProportion * m_cellSize;
    NoughtGraphic nought((m_cellSize - cellPadding) / 2);
    CrossGraphic cross((m_cellSize - cellPadding) / 2);

    for (int x = 0; x < BOARD_SIZE; x ++)
    {
        for (int y = 0; y < BOARD_SIZE; y ++)
        {
            int xPos = x * m_cellSize + m_cellSize / 2 + m_boardLeft;
            int yPos = y * m_cellSize + m_cellSize / 2 + m_boardTop;
            if (m_board.getCell(x, y) == Nought)
                nought.draw(xPos, yPos, m_window, m_backgroundColor);
            else if (m_board.getCell(x, y) == Cross)
                cross.draw(xPos, yPos, m_window);
        }
    }
}

void TicTacToeGame::setCellContents(sf::Event event)
{
    // First calculate board pos of click
    int xCoord = (event.mouseButton.x - m_boardLeft) / m_cellSize;
    int yCoord = (event.mouseButton.y - m_boardTop) / m_cellSize;

    // If click is on board, do game logic
    if (xCoord >= 0 && xCoord < BOARD_SIZE &&
        yCoord >= 0 && yCoord < BOARD_SIZE)
    {
        if (m_board.getCell(xCoord, yCoord) == Empty)
        {
            m_board.setCell(xCoord, yCoord, m_crntPlayer);
            if (m_board.playerHasWon(m_crntPlayer))
            {
                m_gamePhase = ShowingWinner;
            }
            else
            {
                if (m_crntPlayer == Nought) m_crntPlayer = Cross;
                else m_crntPlayer = Nought;
            }
        }
    }
}