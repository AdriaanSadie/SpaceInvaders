#include "player.h"
#include <cmath>
#include <iostream>

void Player::Update() {

  if (!move_idle) {
    if (move_up) 	{ pos_y -= speed; }
    if (move_down)	{ pos_y += speed; } 
    if (move_right)	{ pos_x += speed; }
    if (move_left) 	{ pos_x -= speed; }
  }
  
  // Do some boundary checks
  if (pos_x <= 0) { pos_x = 0; }
  if ((pos_x + width)  >= screen_width) { pos_x = screen_width - width; }
  if (pos_y <= 0) { pos_y = 0; }
  if ((pos_y + height)  >= screen_height) { pos_y = screen_height - height; }
  
}

void Projectile::Update(){
  // Move projectile upwards
  pos_y -= speed;  
}
