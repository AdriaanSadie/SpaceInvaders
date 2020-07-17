#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, Player &player) const {
  
  const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
  SDL_Event event;
  SDL_PollEvent(&event);
  
  if (event.type == SDL_QUIT) {
    running = false;
  } 
  else if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
    
	 player.move_up = false;
     player.move_down = false;
     player.move_left = false;
     player.move_right = false;
     player.move_idle = false; 
	
    // Move centerpoint of rotation for one of the trees:
    if (keyboard_state_array[SDL_SCANCODE_UP])
    {
      player.move_up = true;
    }
    if (keyboard_state_array[SDL_SCANCODE_DOWN])
    {
      player.move_down = true;
    }

    if (keyboard_state_array[SDL_SCANCODE_LEFT])
    {
      player.move_left = true;
    }
    if (keyboard_state_array[SDL_SCANCODE_RIGHT])
    {
      player.move_right = true;
    }
    if ( !keyboard_state_array[SDL_SCANCODE_RIGHT] && !keyboard_state_array[SDL_SCANCODE_LEFT] && !keyboard_state_array[SDL_SCANCODE_UP] && !keyboard_state_array[SDL_SCANCODE_DOWN] ){
      player.move_idle = true;  
    }
  }
  
}
