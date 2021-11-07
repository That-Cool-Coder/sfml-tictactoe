#include "TicTacToeGame.hpp"

void TicTacToeGame::setup()
{
    createBoard();
    createText();
    
    m_board.clear();
    m_crntPlayer = CellValue::Cross; // todo: set this randomly
}

void TicTacToeGame::createText()
{
    m_textEntities.clear();
    m_headingText = std::make_shared<sf::Text>();
    m_headingText->setFont(shared::font);
    m_headingText->setCharacterSize(m_topBarHeight - 15);
    m_headingText->setFillColor(m_textColor);
    // m_drawables.push_back(m_headingText);
}

void TicTacToeGame::createBoard()
{
    m_board = TicTacToeBoard();
}

void TicTacToeGame::update()
{
    calcBoardSize();
    switch (m_gamePhase)
    {
    case Playing:
        drawCellBorders();
        drawCells();
        updateText();
        break;
    case ShowingWinner:
        drawCellBorders();
        drawCells();
        updateText();
        if (! m_showWinnerTimer.running) m_showWinnerTimer.start();
        if (m_showWinnerTimer.isFinished()) gameManager->queueLoadScene("TitleScreen");
        break;
    }
}

void TicTacToeGame::handleEvent(sf::Event& event)
{
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

void TicTacToeGame::updateText()
{
    // Yes this is a big and convoluted nested switch-case
    // But I couldn't find a way to put this into a table lookup because of the differing
    // data types
    std::string headingTextContent = "Error: no text supplied for this heading";
    switch (m_gamePhase)
    {
    case Playing:
        switch (m_crntPlayer)
        {
        case CellValue::Nought:
            headingTextContent = "Noughts turn";
            break;
        case CellValue::Cross:
            headingTextContent = "Crosses turn";
            break;
        }
        break;
    case ShowingWinner:
        switch (m_winner)
        {
        case Winner::Nought:
            headingTextContent = "Noughts wins";
            break;
        case Winner::Cross:
            headingTextContent = "Crosses wins";
            break;
        case Winner::Draw:
            headingTextContent = "Draw";
            break;
        }
        break;
    }
    m_headingText->setString(headingTextContent);
    miniengine::utils::centerAlignText(*m_headingText);
    m_headingText->setPosition(gameManager->width / 2, m_topBarHeight / 2);
}

void TicTacToeGame::calcBoardSize()
{
    int availableHeight = gameManager->height - m_topBarHeight - m_bottomBarHeight;
    m_boardSize = std::min(availableHeight, gameManager->width) - m_windowPadding * 2;
    m_cellSize = m_boardSize / 3;
    m_boardLeft = std::max(gameManager->width - m_boardSize, 1) / 2;
    m_boardTop = std::max(gameManager->height - m_boardSize, 1) / 2;
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
        gameManager->window.draw(rectangle);
    }

    // Do the vertical borders
    rectangle.setRotation(90);
    for (int x = 1; x < BOARD_SIZE; x ++)
    {
        rectangle.setPosition(m_boardLeft + x * m_cellSize,
            m_boardTop + m_boardSize / 2);
        gameManager->window.draw(rectangle);
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
            if (m_board.getCell(x, y) == CellValue::Nought)
                nought.draw(xPos, yPos, gameManager->window, m_backgroundColor);
            else if (m_board.getCell(x, y) == CellValue::Cross)
                cross.draw(xPos, yPos, gameManager->window);
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
        if (m_board.getCell(xCoord, yCoord) == CellValue::Empty)
        {
            m_board.setCell(xCoord, yCoord, m_crntPlayer);
            m_winner = m_board.findWinner();
            if (m_winner == Winner::GameNotFinished)
            {
                if (m_crntPlayer == CellValue::Nought) m_crntPlayer = CellValue::Cross;
                else m_crntPlayer = CellValue::Nought;
            }
            else
            {
                m_gamePhase = ShowingWinner;
            }
        }
    }
}
