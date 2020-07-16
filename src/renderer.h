#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render();
  void UpdateWindowTitle(int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
  SDL_Surface *background_surface;
  SDL_Texture *background_texture;
  SDL_Surface *ship_surface;
  SDL_Texture *ship_texture;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif