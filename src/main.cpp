#include "TicTacToeGame.hpp"
#include "GameManager.hpp"

int main()
{
    GameManager gameManager("Tic Tac Toe");
    TicTacToeGame* game = new TicTacToeGame();
    gameManager.selectScene(game);
    gameManager.mainLoop();
}