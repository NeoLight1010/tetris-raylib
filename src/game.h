#pragma once

#include "block.h"
#include "grid.h"
#include <vector>

class Game {
public:
  Grid grid = Grid();

  Game();
  void draw();

private:
  std::vector<Block *> blocks = getDefaultBlocks();
  Block *currentBlock = popRandomBlock();
  Block *nextBlock = popRandomBlock();

  Block *popRandomBlock();
  std::vector<Block *> getDefaultBlocks();
};
