#include "level.h"
#include <iostream>
#include <string>
#include <algorithm>


void Level::PopulateEnemies(int enemy_layers, int enemy_numbers){
  for (int i = 0; i < enemy_layers; i++){
    for (int j = 1; j <= enemy_numbers; j++){
      Enemy enemy(screen_width/(enemy_numbers+1) * j - 50/2, 50 + 1.5 * 40 * i);  
      enemies.push_back(enemy);
    }
  }
}

void Level::Update(Player &player) {
  // Remove any bullets that collide with enemies, using a predicate function (CheckCollide) inside a lambda. 
  player.bullets.erase(std::remove_if(player.bullets.begin(), player.bullets.end(), [this](Projectile p) { return CheckCollide(p); }), player.bullets.end());
  // After checking collision, update enemy movement
  MoveEnemies();
}

bool Level::CheckCollide(Projectile p){
  // Store original size of enemy vector
  int orig = enemies.size();
  // Remove any enemies that collide with bullets, using a predicate function (CheckRange) inside a lambda
  enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [p, this](Enemy e) { return CheckRange(e, p); } ), enemies.end());
  // Return true if any enemies were removed, thus signalling that bullets need to be removed as well
  return enemies.size() != orig;
}

bool Level::CheckRange(Enemy e, Projectile p){ 
  // Returns true if the enemy coordinates are within a certain range of the projectile coordinates
  return p.pos_x >= (e.pos_x - p.width/2) && p.pos_x <= (e.pos_x + e.width - p.width/2) && p.pos_y <= (e.pos_y + e.height) && p.pos_y <= e.pos_y;
}

void Level::MoveEnemies(){
  // This function handles the movement of the enemies. The movements are simple. They move horizontally (starting in a left direction),
  // until they reach the side of the window. Then the move down for a few (hardcoded) iterations, after which the switch direction and
  // repeat this process.
  
  for (auto &e : enemies){
    if(Enemy_mLeft && !Enemy_mDown){
      // Enemies moving left
      e.pos_x -= e.speed;
      // Check borders (if a single enemy reaches it, the direction changes to down)
      if (e.pos_x <= 0){
        Enemy_mDown = true;  
      }
    }
    else if (Enemy_mRight && !Enemy_mDown){
      // Enemies moving right
      e.pos_x += e.speed;
      // Check borders (if a single enemy reaches it, the direction changes to down)
      if (e.pos_x >= (screen_width - e.width)){
        Enemy_mDown = true;  
      }
    }
    else if (Enemy_mDown){
      // Enemies moving down
      e.pos_y += e.speed;
      down_counter++;
      // Check down counter. When limit reached, change direction from left to right or vice versa
      if (down_counter > 200){
        down_counter = 0;
        Enemy_mDown = false;
        if (Enemy_mLeft) {
          Enemy_mLeft = false;
          Enemy_mRight = true;
        }
        else{
          Enemy_mLeft = true;
          Enemy_mRight = false;
        }
      }
    }
  }
}
