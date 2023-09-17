#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fish.h"
#include <memory>

class Controller {
 public:
  void HandleInput(bool &running, std::unique_ptr<Fish> &fish);
  int count {0};
};

#endif