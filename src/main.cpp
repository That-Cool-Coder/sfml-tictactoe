#include "TicTacToeGame.hpp"
#include "GameManager.hpp"

int main()
{
    GameManager gameManager;
    gameManager.mainLoop();
    TicTacToeGame().mainLoop();
}