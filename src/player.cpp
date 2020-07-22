#include "player.h"
#include <cmath>
#include <iostream>
#include <algorithm>

// Getters and Setters:


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
  
  
  // Update bullets:
  for (auto& i : bullets){
    i.Update();
  }
  bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Projectile p) { return p.getPosY() < -p.getHeight(); }), bullets.end());
  
}

void Player::Shoot() {
  Projectile bullet(pos_x + width/2 - 6, pos_y);
  bullets.push_back(bullet);
}

void Player::Initialise() {
  pos_x = screen_width / 2  - width / 2.0;
  pos_y = screen_height * (0.9);
  bullets.clear();
}

void Projectile::Update(){
  // Move projectile upwards
  pos_y -= speed;  
}
