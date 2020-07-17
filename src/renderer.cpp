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
  
  // Load player image and background:
  background_surface = SDL_LoadBMP("back.bmp"); 
  background_texture = SDL_CreateTextureFromSurface(sdl_renderer, background_surface); // Convert surface to texture
  SDL_FreeSurface(background_surface); // Free surface since we will only be using texture from now on
  ship_surface = IMG_Load("ship.png");
  ship_texture = SDL_CreateTextureFromSurface(sdl_renderer, ship_surface); // Convert surface to texture
  SDL_FreeSurface(ship_surface); // Free surface since we will only be using texture from now on
}

Renderer::~Renderer() {
  SDL_DestroyTexture(background_texture);
  SDL_DestroyTexture(ship_texture);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Player const player) {

  // Clear screen
  //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  //SDL_RenderClear(sdl_renderer);
 
  // Render background
  SDL_RenderCopy(sdl_renderer, background_texture, NULL, NULL);
  
  // Render ship
  SDL_Rect dstrect = { (int)player.pos_x, (int)player.pos_y, player.player_width, player.player_height };
  SDL_RenderCopy(sdl_renderer, ship_texture, NULL, &dstrect);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int fps) {
  std::string title{"Space Invaders --  FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
