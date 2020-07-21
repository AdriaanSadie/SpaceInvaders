#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "renderer.h"
#include "player.h"
#include "controller.h"
#include "level.h"
#include <string>


class Game {
 public:
  Game(int screen_width, int screen_height);
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  void Update();
  
 private:
  
  int difficulty = 1;
  int enemy_layers = 1;
  int enemy_numbers = 5;
  std::string high_score_name = "";
  int high_score_value = 0;
  
  void LoadConfig(int,int&,int&,std::string&,int&);
  Player player;
  Level level;
  int screen_width;
  int screen_height;

};

#endif