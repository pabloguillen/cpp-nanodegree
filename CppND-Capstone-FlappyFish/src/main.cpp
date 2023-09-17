#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {

  //intialize basic properties
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};

  //create controller object
  Controller controller;

  //create render object
  std::unique_ptr<Renderer> renderer =  std::make_unique<Renderer> (kScreenWidth, kScreenHeight);

  //create game object
  Game game(kScreenWidth, kScreenHeight);

  //run game
  game.Run(std::move(controller), std::move(renderer), kMsPerFrame);

  //print out termination message
  std::cout << "Game has terminated successfully!\n";

  //print out score
  std::cout << "Score: " << game.GetScore() << "\n";

  return 0;
}