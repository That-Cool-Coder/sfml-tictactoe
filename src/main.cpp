#include <memory>
#include "shared.hpp"
#include "miniengine/miniengine.hpp"
#include "TicTacToeGame.hpp"
#include "TitleScreen.hpp"

int main()
{
    shared::loadFont("SpaceGrotesk-Regular.otf");
    miniengine::GameManager gameManager("Tic Tac Toe");
    gameManager.scenes["TicTacToeGame"] = [&] { return std::make_shared<TicTacToeGame>(); };
    gameManager.scenes["TitleScreen"] = [&] { return std::make_shared<TitleScreen>(); };
    gameManager.loadScene(std::make_shared<TitleScreen>());
    gameManager.mainLoop();
}