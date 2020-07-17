#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Player {
public:
  enum class Direction { kLeft, kRight, kUp, kDown, kIdle};
  
  Player(int screen_width, int screen_height) : pos_x(screen_width/2), pos_y(screen_height/2), screen_width(screen_width), screen_height(screen_height) {}
  
  void Update();

  Direction direction = Direction::kIdle;
  
  float speed = 4;
  bool alive = true;
  float pos_x;
  float pos_y;
  int player_width = 50;
  int player_height = 50;
  
  bool move_up = false;
  bool move_down = false;
  bool move_right = false;
  bool move_left = false;
  bool move_idle = true;
  
private:
  
  int screen_width;
  int screen_height;

};

#endif