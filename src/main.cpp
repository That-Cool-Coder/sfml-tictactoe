#include <memory>
#include "shared.hpp"
#include "GameManager.hpp"
#include "TicTacToeGame.hpp"
#include "TitleScreen.hpp"

int main()
{
    shared::loadFont("SpaceGrotesk-Regular.otf");
    GameManager gameManager("Tic Tac Toe");
    gameManager.scenes["TicTacToeGame"] = [&] { return std::make_shared<TicTacToeGame>(); };
    gameManager.scenes["TitleScreen"] = [&] { return std::make_shared<TitleScreen>(); };
    gameManager.loadScene("TitleScreen");
    gameManager.mainLoop();
}