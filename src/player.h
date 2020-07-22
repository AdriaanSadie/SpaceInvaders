#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Projectile {
public:
  // Constructor
  Projectile(float x, float y) : pos_x(x), pos_y(y) {}
  // Public methods
  void Update();
  // Getters and Setters:
  float getSpeed() { return speed; }
  int getWidth() { return width; }
  int getHeight() { return height; }
  float getPosX() { return pos_x; }
  float getPosY() { return pos_y; }
  void changePosY(float s){ pos_y += s; } // Will either increment or decrement position, based on input (bullets moving up/down)

private:
  float speed = 5;
  int width = 12;
  int height = 29;
  float pos_x;
  float pos_y;
};

class Player {
public:
  // Constructor
  Player(int screen_width, int screen_height) : screen_width(screen_width), screen_height(screen_height) {}
  // Public methods
  void Update();
  void Shoot();
  void Initialise();

  // Getters and setters
  float getSpeed() { return speed; }
  bool getAlive() { return alive; }
  float getPosX() { return pos_x; }
  float getPosY() { return pos_y; }
  int getWidth() { return width; }
  int getHeight() { return height; }

  // Public members
  std::vector<Projectile> bullets;
  
  bool move_up = false;
  bool move_down = false;
  bool move_right = false;
  bool move_left = false;
  bool move_idle = true;
  
private:
  float speed = 4;
  bool alive = true;
  float pos_x;
  float pos_y;
  int width = 50;
  int height = 50;
  
  int screen_width;
  int screen_height;

};

#endif