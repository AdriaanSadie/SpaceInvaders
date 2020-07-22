#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height) : screen_width(screen_width), screen_height(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  
  // Load all assets:
  background_surface = SDL_LoadBMP("assets/back.bmp"); // Background
  gameover_surface = SDL_LoadBMP("assets/gameover.bmp"); // GameOver screen
  victory_surface = SDL_LoadBMP("assets/victoryscreen.bmp"); // Victory screen
  ship_surface = IMG_Load("assets/ship.png"); // Spaceship
  bullet_surface = IMG_Load("assets/bullet.png"); // Bullets
  alien1_surface = IMG_Load("assets/alien1.png"); // Enemies
  laser_surface = IMG_Load("assets/laser.png"); // Enemy lasers
  
  // Convert surface to texture
  background_texture = SDL_CreateTextureFromSurface(sdl_renderer, background_surface); 
  gameover_texture = SDL_CreateTextureFromSurface(sdl_renderer, gameover_surface);
  victory_texture = SDL_CreateTextureFromSurface(sdl_renderer, victory_surface);
  ship_texture = SDL_CreateTextureFromSurface(sdl_renderer, ship_surface); 
  bullet_texture = SDL_CreateTextureFromSurface(sdl_renderer, bullet_surface);
  alien1_texture = SDL_CreateTextureFromSurface(sdl_renderer, alien1_surface);
  laser_texture = SDL_CreateTextureFromSurface(sdl_renderer, laser_surface);
  
  // Free surfaces since we will only be using textures from now on
  SDL_FreeSurface(background_surface);
  SDL_FreeSurface(gameover_surface);
  SDL_FreeSurface(victory_surface);
  SDL_FreeSurface(ship_surface);
  SDL_FreeSurface(bullet_surface); 
  SDL_FreeSurface(alien1_surface); 
  SDL_FreeSurface(laser_surface); 
}

Renderer::~Renderer() {
  SDL_DestroyTexture(background_texture);
  SDL_DestroyTexture(ship_texture);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Player const player, Level const level) {

  // Clear screen
  //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  //SDL_RenderClear(sdl_renderer);
 
  // Render background
  SDL_RenderCopy(sdl_renderer, background_texture, NULL, NULL);
  
  // Render ship
  SDL_Rect player_rect = { (int)player.pos_x, (int)player.pos_y, player.width, player.height };
  SDL_RenderCopy(sdl_renderer, ship_texture, NULL, &player_rect);
  
  // Render bullets
  for (auto i : player.bullets) {
    SDL_Rect bullet = { (int)i.pos_x, (int)i.pos_y, i.width, i.height };
    SDL_RenderCopy(sdl_renderer, bullet_texture, NULL, &bullet);
  }
  
  // Render enemies
  for (auto i : level.enemies) {
    SDL_Rect enemy = { (int)i.pos_x, (int)i.pos_y, i.width, i.height };
    SDL_RenderCopy(sdl_renderer, alien1_texture, NULL, &enemy);  
  }
  
  // Render enemy bullets
  for (auto i : level.lasers) {
    SDL_Rect laser = { (int)i.pos_x, (int)i.pos_y, i.width, i.height };
    SDL_RenderCopy(sdl_renderer, laser_texture, NULL, &laser);  
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::RenderFinalScreen(bool win){
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  
  // Render Screen
  if(win){
    SDL_RenderCopy(sdl_renderer, victory_texture, NULL, NULL);  
  }
  else{
    SDL_RenderCopy(sdl_renderer, gameover_texture, NULL, NULL);  
  }
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int fps, int bullets) {
  std::string title{"Space Invaders --  FPS: " + std::to_string(fps) + " bullets: " + std::to_string(bullets)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
