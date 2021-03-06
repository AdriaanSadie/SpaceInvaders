#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "SDL.h"
#include "player.h"

class Enemy {
public:
  // Constructor
  Enemy(float x, float y) : pos_x(x), pos_y(y) {}  
  // Getters and Setters
  float getPosX() { return pos_x; }
  float getPosY() { return pos_y; }
  float getSpeed() { return speed; }
  int getWidth() { return width; }
  int getHeight() { return height; }
  bool getAlive() { return alive; }  
  
  void changePosX(float s) { pos_x += s; }
  void changePosY(float s) { pos_y += s; }
  
private:
  float pos_x;
  float pos_y;
  float speed = 1;
  int width = 40;
  int height = 40;
  bool alive = true;
};

class Level {
public:
  // Constructor
  Level(int screen_width, int screen_height) : screen_width(screen_width), screen_height(screen_height) {}
  // Public methods
  void PopulateEnemies(int, int);  
  void Update(Player&, bool&);
  bool CheckCollideEnemy(Projectile);
  bool CheckCollidePlayer(Player, Projectile);
  bool CheckRangeEnemy(Enemy, Projectile);
  void MoveEnemies();
  void EnemyShootLoop(bool &);
  void EnemyShoot(int);
  void UpdateLasers();
  
  // Public members
  std::vector<Enemy> enemies;
  std::vector<Projectile> lasers; // The enemies' lasers
  
  bool Enemy_mLeft = true;
  bool Enemy_mDown = false;
  int down_counter = 0;
  int difficulty = 1;
  
private:
  int screen_width;
  int screen_height;
};

#endif