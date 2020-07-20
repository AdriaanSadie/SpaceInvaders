#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "SDL.h"
#include "player.h"

class Enemy {
public:
  
  Enemy(float x, float y) : pos_x(x), pos_y(y) {}  
  float pos_x;
  float pos_y;
  float speed = 0.4;
  int width = 40;
  int height = 40;
  bool alive = true;
private:
  
};

class Level {
public:
  int difficulty = 1;
  void PopulateEnemies(int, int);  
  void Update(Player&);
  bool CheckCollide(Projectile);
  bool CheckRange(Enemy, Projectile);
  void MoveEnemies();
  std::vector<Enemy> enemies;
  
private:
  
};

#endif