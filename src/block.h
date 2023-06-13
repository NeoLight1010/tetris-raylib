#pragma once

#include "position.h"
#include <map>
#include <vector>

struct Block {
public:
  std::map<int, std::vector<Position>> cells; // TODO Rename to rotations

  Block();
  void draw();
  void move(int rows, int columns);
  virtual int id() = 0;

private:
  int cellSize = 30;
  int rotationState = 0;
  int rowOffset = 0;
  int columnOffset = 0;

  std::vector<Position> getMovedCellPositions();
};
