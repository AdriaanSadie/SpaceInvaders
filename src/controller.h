#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include <vector>

class Controller {
 public:
  void HandleInput(bool &running, Player &player, std::vector<Projectile> &bullets) const;

 private:
};

#endif