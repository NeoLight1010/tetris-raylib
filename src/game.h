#pragma once

#include "block.h"
#include "grid.h"
#include <memory>
#include <vector>

class GameEventHandler {
public:
  virtual void onRowsClear() = 0;
};

class Game {
public:
  const static int CELL_SIZE = 30;
  const static int PADDING_SIZE = 10;

  bool gameOver = false;

  Grid grid = Grid();

  Game(GameEventHandler &eventHandler);
  void applyGravity();
  void draw();
  void restart();

  std::shared_ptr<Block> getCurrentBlock() { return currentBlock; }
  std::shared_ptr<Block> getNextBlock() { return nextBlock; }
  int getScore() { return score; }

  void moveBlockLeft();
  void moveBlockRight();
  void moveBlockDown();

  void rotateBlockForward();
  void rotateBlockBackward();

  void giveScoreForManualDrop() { score += 1; };

private:
  GameEventHandler &eventHandler;

  int score = 0;

  std::vector<std::shared_ptr<Block>> blocks = getDefaultBlocks();
  std::shared_ptr<Block> currentBlock = popRandomBlock();
  std::shared_ptr<Block> nextBlock = popRandomBlock();

  std::shared_ptr<Block> popRandomBlock();
  std::vector<std::shared_ptr<Block>> getDefaultBlocks();

  void drawGrid();

  void giveScoreForFullRows(int fullRows);

  bool isBlockOutsideGrid();
  bool blockFits();

  void lockBlockAndSpawnNextBlock();

  bool moveBlockIfItFits(int rows, int columns);
};
