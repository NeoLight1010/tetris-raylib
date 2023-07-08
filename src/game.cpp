#include "game.h"
#include "blocks.cpp"
#include "position.h"
#include "raylib.h"
#include <iostream>
#include <memory>
#include <random>
#include <vector>

Game::Game(){};

std::shared_ptr<Block> Game::popRandomBlock() {
  if (blocks.empty()) {
    blocks = getDefaultBlocks();
  }

  int randomIndex = rand() % blocks.size();
  std::shared_ptr<Block> chosenBlock = blocks[randomIndex];

  blocks.erase(blocks.begin() + randomIndex);

  chosenBlock->center();
  return chosenBlock;
};

std::vector<std::shared_ptr<Block>> Game::getDefaultBlocks() {
  return {std::make_unique<SBlock>(), std::make_unique<ZBlock>(),
          std::make_unique<TBlock>(), std::make_unique<LBlock>(),
          std::make_unique<JBlock>(), std::make_unique<OBlock>(),
          std::make_unique<IBlock>()};
};

void Game::draw() {
  grid.draw();
  currentBlock->draw();
};

void Game::handleInput() {
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
  case KEY_LEFT:
    moveBlockLeft();
    break;
  case KEY_RIGHT:
    moveBlockRight();
    break;
  case KEY_DOWN:
    moveBlockDown();
    break;

  case KEY_Z:
    rotateBlockBackward();
    break;

  case KEY_X:
    rotateBlockForward();
    break;
  }
}

void Game::checkForFullRows() { grid.popFullRows(); }

bool Game::isBlockOutsideGrid() {
  std::vector<Position> currentBlockCells =
      currentBlock->getMovedCellPositions();

  for (auto cellPosition : currentBlockCells) {
    if (grid.isCellOutside(cellPosition.row, cellPosition.column)) {
      return true;
    }
  }

  return false;
}

bool Game::blockFits() {
  for (auto cellPosition : currentBlock->getMovedCellPositions()) {
    if (!grid.isCellEmpty(cellPosition.row, cellPosition.column)) {
      return false;
    }
  }

  return true;
}

void Game::moveBlockLeft() { moveBlockIfItFits(0, -1); }
void Game::moveBlockRight() { moveBlockIfItFits(0, 1); }

void Game::moveBlockDown() {
  bool blockWasMoved = moveBlockIfItFits(1, 0);

  if (!blockWasMoved) {
    lockBlockAndSpawnNextBlock();
  }
}

bool Game::moveBlockIfItFits(int rows, int columns) {
  currentBlock->move(rows, columns);

  bool blockWasMoved = true;

  if (isBlockOutsideGrid() || !blockFits()) {
    currentBlock->move(-rows, -columns);
    blockWasMoved = false;
  }

  return blockWasMoved;
}

void Game::rotateBlockForward() {
  currentBlock->rotateForward();

  if (isBlockOutsideGrid()) {
    currentBlock->rotateBackward();
  }
}

void Game::rotateBlockBackward() {
  currentBlock->rotateBackward();

  if (isBlockOutsideGrid()) {
    currentBlock->rotateForward();
  }
}

void Game::applyGravity() { moveBlockDown(); }

void Game::lockBlockAndSpawnNextBlock() {
  std::vector<Position> currentBlockCells =
      currentBlock->getMovedCellPositions();

  for (Position cellPosition : currentBlockCells) {
    grid.setCellValue(cellPosition.row, cellPosition.column,
                      currentBlock->id());
  }

  currentBlock = nextBlock;
  nextBlock = popRandomBlock();
}
