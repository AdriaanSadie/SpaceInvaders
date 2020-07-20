#include "level.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>


void Level::PopulateEnemies(int screen_width, int screen_height, int difficulty){

  std::string key;
  std::string value1, value2;
  std::string line;
  
  int layers;
  int numbers;
  int size = 40;
  
  std::ifstream cfg_file("config.txt");
  if(cfg_file.is_open()){
    while(std::getline(cfg_file, line)){
      std::istringstream linestream(line);
      linestream >> key >> value1 >> value2;
      if(key == "HIGH_SCORE"){
        
      }
      else{
        switch(difficulty){
          case 1:
            if(key == "ENEMY_DIFF_EASY") {
              layers = std::stoi(value1);
              numbers = std::stoi(value2);
            }
            break;
            
          case 2:
            if(key == "ENEMY_DIFF_MEDIUM") {
              layers = std::stoi(value1);
              numbers = std::stoi(value2);
            }
           	break;
            
          case 3:
            if(key == "ENEMY_DIFF_HARD") {
              layers = std::stoi(value1);
              numbers = std::stoi(value2);
            }
            break;
        }
      }
    }
  }
  else{
    std::cout << "Could not open config file!" << std::endl;  
  }
  
  for (int i = 0; i < layers; i++){
    for (int j = 1; j <= numbers; j++){
      Enemy enemy(screen_width/(numbers+1) * j - 50/2, 50 + 1.5 * size * i);  
      enemies.push_back(enemy);
    }
  }
  
}

void Level::Update(Player &player) {
  player.bullets.erase(std::remove_if(player.bullets.begin(), player.bullets.end(), [this](Projectile p) { return CheckCollide(p); }), player.bullets.end());
  //MoveEnemies();
}

bool Level::CheckCollide(Projectile p){
  int orig = enemies.size();
  
  enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [p, this](Enemy e) { return CheckRange(e, p); } ), enemies.end());
  
  return enemies.size() != orig;
}

bool Level::CheckRange(Enemy e, Projectile p){
  //return p.pos_x >= e.pos_x && p.pos_x <= (e.pos_x + e.width) && p.pos_y <= (e.pos_y + e.height) && p.pos_y <= e.pos_y;
  
  return p.pos_x >= (e.pos_x - p.width/2) && p.pos_x <= (e.pos_x + e.width - p.width/2) && p.pos_y <= (e.pos_y + e.height) && p.pos_y <= e.pos_y;
}

void Level::MoveEnemies(){
  for (auto& e : enemies){
    e.pos_x -= e.speed;
  }
}
