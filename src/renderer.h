#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "player.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Player const player);
  void UpdateWindowTitle(int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
  SDL_Surface *background_surface = nullptr;
  SDL_Texture *background_texture = nullptr;
  SDL_Surface *ship_surface = nullptr;
  SDL_Texture *ship_texture = nullptr;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif