#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"


class Game {
 public:
  Game();
  void Run(Renderer &renderer, std::size_t target_frame_duration);
  
 private:

};

#endif