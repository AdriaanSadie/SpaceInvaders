#include "player.h"
#include <cmath>
#include <iostream>

void Player::Update() {
  switch (direction) {
    case Direction::kLeft:
      pos_x -= speed;
      break;
      
    case Direction::kRight:
      pos_x += speed;
      break;
      
    case Direction::kUp:
      pos_y -= speed;
      break;
      
    case Direction::kDown:
      pos_y += speed;
    
    case Direction::kIdle:
      break;
  }
  
  // Do some boundary checks
  if (pos_x <= 0) { pos_x = 0; }
  if ((pos_x + player_width)  >= screen_width) { pos_x = screen_width - player_width; }
  if (pos_y <= 0) { pos_y = 0; }
  if ((pos_y + player_height)  >= screen_height) { pos_y = screen_height - player_height; }
  
}
