#include "level.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

#include <thread>
#include <chrono>

void Level::PopulateEnemies(int enemy_layers, int enemy_numbers){
  enemies.clear();
  lasers.clear();
  for (int i = 0; i < enemy_layers; i++){
    for (int j = 1; j <= enemy_numbers; j++){
      Enemy enemy(screen_width/(enemy_numbers+1) * j - 50/2, 50 + 1.5 * 40 * i);  
      enemies.push_back(enemy);
    }
  }
}

void Level::Update(Player &player, bool &game_running) {
  // Remove any bullets that collide with enemies, using a predicate function (CheckCollide) inside a lambda. 
  player.bullets.erase(std::remove_if(player.bullets.begin(), player.bullets.end(), [this](Projectile p) { return CheckCollideEnemy(p); }), player.bullets.end());
  // Remove any enemy lasers that collide with the player and set: 
  int laser_len = lasers.size();
  lasers.erase(std::remove_if(lasers.begin(), lasers.end(), [player, this](Projectile p) { return CheckCollidePlayer(player, p); } ), lasers.end());
  if (laser_len != lasers.size()) { game_running = false; } // End game since laser hit the player
  // After checking collision, update enemy movement
  MoveEnemies();
  UpdateLasers();
}

bool Level::CheckCollidePlayer(Player p, Projectile l){
  return l.getPosX() >= (p.getPosX() - l.getWidth()/2) && l.getPosX() <= (p.getPosX() + p.getWidth() - l.getWidth()/2) && l.getPosY() <= (p.getPosY() + p.getHeight()) && l.getPosY() >= p.getPosY();
}

bool Level::CheckCollideEnemy(Projectile p){
  // Store original size of enemy vector
  int orig = enemies.size();
  // Remove any enemies that collide with bullets, using a predicate function (CheckRange) inside a lambda
  enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [p, this](Enemy e) { return CheckRangeEnemy(e, p); } ), enemies.end());
  // Return true if any enemies were removed, thus signalling that bullets need to be removed as well
  return enemies.size() != orig;
}

bool Level::CheckRangeEnemy(Enemy e, Projectile p){ 
  // Returns true if the enemy coordinates are within a certain range of the projectile coordinates
  return p.getPosX() >= (e.getPosX() - p.getWidth()/2) && p.getPosX() <= (e.getPosX() + e.getWidth() - p.getWidth()/2) && p.getPosY() <= (e.getPosY() + e.getHeight()) && p.getPosY() >= e.getPosY();
}

void Level::MoveEnemies(){
  // This function handles the movement of the enemies. The movements are simple. They move horizontally (starting in a left direction),
  // until they reach the side of the window. Then the move down for a few (hardcoded) iterations, after which the switch direction and
  // repeat this process.
  
  for (auto &e : enemies){
    if(Enemy_mLeft && !Enemy_mDown){
      // Enemies moving left
      e.changePosX(-1 * e.getSpeed());
      // Check borders (if a single enemy reaches it, the direction changes to down)
      if (e.getPosX() <= 0){
        Enemy_mDown = true;  
      }
    }
    else if (!Enemy_mLeft && !Enemy_mDown){
      // Enemies moving right
      e.changePosX(e.getSpeed());
      // Check borders (if a single enemy reaches it, the direction changes to down)
      if (e.getPosX() >= (screen_width - e.getWidth())){
        Enemy_mDown = true;  
      }
    }
    else if (Enemy_mDown){
      // Enemies moving down
      e.changePosY(e.getSpeed());
      down_counter++;
      // Check down counter. When limit (hardcoded) reached, change direction from left to right or vice versa
      if (down_counter > 150){
        down_counter = 0;
        Enemy_mDown = false;
        if (Enemy_mLeft) { Enemy_mLeft = false; }
        else{ Enemy_mLeft = true; }
      }
    }
  }
}

void Level::EnemyShootLoop(bool &running){
  while(running){
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Only call shoot every 0.5 seconds
    EnemyShoot(2); // 2/10 chance for each enemy to shoot
  }
}

void Level::EnemyShoot(int chance){
  // Here we generate lasers from random enemies by using a random number generator. 
  int rand_num;
  srand (time(NULL));
  
  // Loop through all enemies. Base on the chance factor input, the enemy will shoot and add projectile to vector
  for (auto e: enemies){
    // Generate random number between 1 and 10
    rand_num = rand() % 10 + 1;
    if (rand_num <= chance){
      Projectile laser(e.getPosX() + e.getWidth()/2.0 - 6, e.getPosY());
      lasers.push_back(laser);
    }
  }
}

void Level::UpdateLasers(){
  for (auto &b : lasers) {
    b.changePosY(b.getSpeed());
  }
}

