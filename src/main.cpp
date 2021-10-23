#include "TicTacToeGame.hpp"
#include "GameManager.hpp"

int main()
{
    GameManager gameManager;
    TicTacToeGame* game = new TicTacToeGame();
    gameManager.selectScene(game);
    gameManager.mainLoop();
}