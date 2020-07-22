#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "player.h"
#include "level.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Player const player, Level const level);
  void RenderMenu();
  void RenderFinalScreen(bool win);
  void UpdateWindowTitle(int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
  SDL_Surface *menu_surface = nullptr;
  SDL_Texture *menu_texture = nullptr;
  SDL_Surface *background_surface = nullptr;
  SDL_Texture *background_texture = nullptr;
  SDL_Surface *gameover_surface = nullptr;
  SDL_Texture *gameover_texture = nullptr;
  SDL_Surface *victory_surface = nullptr;
  SDL_Texture *victory_texture = nullptr;
  SDL_Surface *ship_surface = nullptr;
  SDL_Texture *ship_texture = nullptr;
  SDL_Surface *bullet_surface = nullptr;
  SDL_Texture *bullet_texture = nullptr;
  SDL_Surface *laser_surface = nullptr;
  SDL_Texture *laser_texture = nullptr;
  SDL_Surface *alien1_surface = nullptr;
  SDL_Texture *alien1_texture = nullptr;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif