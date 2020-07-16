#include <iostream>
#include "renderer.h"
#include "game.h"


int main() {
  // Game window refresh rate:
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  // Game window size:
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  
  // Create render object to handle the visual output of the game
  Renderer renderer(kScreenWidth, kScreenHeight);
  // Create game object that runs the game loop
  Game game;
  // Call run function, by giving the game the render and controller objects as well as the desired framerate of the game window
  game.Run(renderer, kMsPerFrame);
  
  return 0;
}