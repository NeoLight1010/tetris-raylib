#pragma once

#include "block.h"
#include "grid.h"
#include <memory>
#include <vector>

class Game {
public:
  Grid grid = Grid();

  Game();
  void draw();
  void handleInput();

private:
  std::vector<std::shared_ptr<Block>> blocks = getDefaultBlocks();
  std::shared_ptr<Block> currentBlock = popRandomBlock();
  std::shared_ptr<Block> nextBlock = popRandomBlock();

  std::shared_ptr<Block> popRandomBlock();
  std::vector<std::shared_ptr<Block>> getDefaultBlocks();

  bool isBlockOutsideGrid();

  void moveBlockLeft();
  void moveBlockRight();
  void moveBlockDown();
};
