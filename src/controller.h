#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include <vector>

class Controller {
 public:
  void HandleInput(bool &running, Player &player) const;
  int HandleMenuInput(bool &running) const;

 private:
};

#endif