#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "renderer.h"
#include "player.h"
#include "controller.h"


class Game {
 public:
  Game(int screen_width, int screen_height);
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  void Update();
  
 private:
  Player player;
  std::vector<Projectile> bullets;
  int screen_width;
  int screen_height;

};

#endif