#include <iostream>
#include <string>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::string player;
  std::cout << "Please input your name: ";
  std::cin >> player;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  game.print("Score", game.GetScore());
  game.print("Size", game.GetSize());

  std::ofstream file_writer("scores.txt", std::ios::app);
  if (file_writer.is_open())
  {    
    file_writer << player << "\tScore:" << game.GetScore() << "\n";
    file_writer.close();
    std::cout << "Your score is saved into scores.txt" << "\n";
  }
  return 0;
}