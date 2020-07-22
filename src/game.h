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
#include <thread>

class Game {
 public:
  enum class GameState {kMenuState, kInitializeState, kRunningState, kGameOverState};
  
  Game(int screen_width, int screen_height);
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  void Update();
  
 private:
  
  int difficulty = 0; // Can be 1 (Easy), 2 (Medium), 3 (Hard)  Default is 0 - require input from user to change
  int enemy_layers = 1;
  int enemy_numbers = 5;
  bool win = false;
  bool game_running = true;
  bool app_running = true;
  std::string high_score_name = "";
  int high_score_value = 0;
  std::thread t1;
  
  GameState game_state = GameState::kMenuState;
  
  void LoadConfig(int,int&,int&,std::string&,int&);
  Player player;
  Level level;
  int screen_width;
  int screen_height;

};

#endif