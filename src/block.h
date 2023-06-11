#pragma once

#include "position.h"
#include <map>
#include <vector>

struct Block {
public:
  std::map<int, std::vector<Position>> cells;

  Block();
  void draw();
  virtual int id() = 0;

private:
  int cellSize = 30;
  int rotationState = 0;
};
