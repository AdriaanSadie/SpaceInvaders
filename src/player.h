#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Projectile {
public:
  
  Projectile(float x, float y) : pos_x(x), pos_y(y) {}
  
  void Update();
  
  float speed = 5;
  int width = 40;
  int height = 40;
  float pos_x;
  float pos_y;
private:
  //Some stuff
};

class Player {
public:
  
  Player(int screen_width, int screen_height) : pos_x(screen_width/2), pos_y(screen_height/2), screen_width(screen_width), screen_height(screen_height) {}
  
  void Update();

  float speed = 4;
  bool alive = true;
  float pos_x;
  float pos_y;
  int width = 50;
  int height = 50;
  
  bool move_up = false;
  bool move_down = false;
  bool move_right = false;
  bool move_left = false;
  bool move_idle = true;
  
private:
  
  int screen_width;
  int screen_height;
  
  //

};

#endif