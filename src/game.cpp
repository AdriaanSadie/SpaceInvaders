#include "game.h"
#include <iostream>
#include "SDL.h"
#include <fstream>
#include <sstream>

#include <thread>
#include <chrono>

Game::Game(int screen_width, int screen_height) : player(screen_width, screen_height), screen_width(screen_width), screen_height(screen_height), level(screen_width, screen_height) {}

void Game::Update() {  
  player.Update();
  level.Update(player, game_running);
}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  while(app_running){
  
    switch(game_state){
      case GameState::kMenuState:
        while(true){
          renderer.RenderMenu();
          difficulty = controller.HandleMenuInput(app_running);
          if(difficulty != 0 || !app_running) { break; }
          std::this_thread::sleep_for(std::chrono::milliseconds(1)); //So that the constant while loop doesn't wreck the CPU
        }
        game_state = GameState::kInitializeState;
        break;
        
      case GameState::kInitializeState:
        // Load info from config file: 
        // -- Depending on difficulty level, loads different values of enemies (layers and numbers)
        // -- Loads the high score and the name associated with it
        
        LoadConfig(difficulty, enemy_layers, enemy_numbers, high_score_name, high_score_value);
        level.PopulateEnemies(enemy_layers, enemy_numbers);
        player.Initialise();
        t1 = std::thread(&Level::EnemyShootLoop, &level, std::ref(game_running));
        
        win = false;
        game_running = true;
        app_running = true;
        
        game_state = GameState::kRunningState;
        break;
      
      case GameState::kRunningState:
        
        while (game_running) {
          frame_start = SDL_GetTicks();

          // Input, Update, Render - the main game loop.
          controller.HandleInput(app_running, player);
          if(!app_running) { game_running = false; } //break if ESC or SDL_QUIT is called in controller.HandleInput()
          Update();
          renderer.Render(player, level);
          
          // Check if game is won (no more enemies):
          if (level.enemies.size() == 0){
            win = true;  
            game_running = false;
          }

          frame_end = SDL_GetTicks();

          // Keep track of how long each loop through the input/update/render cycle takes.
          frame_count++;
          frame_duration = frame_end - frame_start;

          // After every second, update the window title.
          if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(frame_count, player.bullets.size());
            frame_count = 0;
            title_timestamp = frame_end;
          }

          // If the time for this frame is too small (i.e. frame_duration is
          // smaller than the target ms_per_frame), delay the loop to
          // achieve the correct frame rate.
          if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
          }
        }
  
        t1.join();
        
        game_state = GameState::kGameOverState;
        break;
      
      case GameState::kGameOverState:
        renderer.RenderFinalScreen(win);
        SDL_Delay(4000);
        game_state = GameState::kMenuState;
        //app_running = false;
        break;
    }
  }
}

void Game::LoadConfig(int difficulty, int &enemy_layers, int &enemy_numbers, std::string &high_score_name, int &high_score_value){
  
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
        high_score_name = value1;
        high_score_value = std::stoi(value2);
      }
      else{
        switch(difficulty){
          case 1:
            if(key == "ENEMY_DIFF_EASY") {
              enemy_layers = std::stoi(value1);
              enemy_numbers = std::stoi(value2);
            }
            break;
            
          case 2:
            if(key == "ENEMY_DIFF_MEDIUM") {
              enemy_layers = std::stoi(value1);
              enemy_numbers = std::stoi(value2);
            }
           	break;
            
          case 3:
            if(key == "ENEMY_DIFF_HARD") {
              enemy_layers = std::stoi(value1);
              enemy_numbers = std::stoi(value2);
            }
            break;
        }
      }
    }
  }
  else{
    std::cout << "Could not open config file!" << std::endl;  
  }
}



