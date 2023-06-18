#include "game.h"
#include "blocks.cpp"
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

void Game::moveBlockLeft() {
  currentBlock->move(0, -1);

  if (isBlockOutsideGrid()) {
    currentBlock->move(0, 1);
  }
}

void Game::moveBlockRight() {
  currentBlock->move(0, 1);

  if (isBlockOutsideGrid()) {
    currentBlock->move(0, -1);
  }
}
void Game::moveBlockDown() {
  currentBlock->move(1, 0);

  if (isBlockOutsideGrid()) {
    currentBlock->move(-1, 0);
  }
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
