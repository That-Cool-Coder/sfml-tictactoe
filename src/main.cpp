#include <memory>
#include "TicTacToeGame.hpp"
#include "GameManager.hpp"

int main()
{
    GameManager gameManager("Tic Tac Toe");
    gameManager.scenes["TicTacToeGame"] = [&] { return std::make_shared<TicTacToeGame>(); };
    gameManager.loadScene("TicTacToeGame");
    gameManager.mainLoop();
}