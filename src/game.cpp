#include "game.h"
#include <iostream>
#include "SDL.h"
#include <algorithm>

Game::Game(int screen_width, int screen_height) : player(screen_width, screen_height), screen_width(screen_width), screen_height(screen_height) {}

void Game::Update() {  
  player.Update();
  for (auto& i : bullets){
    i.Update();
  }
  
  bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Projectile p) { return p.pos_y < -p.height; }), bullets.end());
}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
	controller.HandleInput(running, player, bullets);
    Update();
    renderer.Render(player, bullets);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(frame_count, bullets.size());
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
}



