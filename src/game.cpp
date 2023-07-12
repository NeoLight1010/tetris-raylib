#include "game.h"
#include "blocks.cpp"
#include "colors.h"
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
  drawGrid();
};

void Game::handleInput() {
  int keyPressed = GetKeyPressed();

  if (gameOver && keyPressed != 0) {
    restart();
    return;
  }

  switch (keyPressed) {
  case KEY_LEFT:
    moveBlockLeft();
    break;
  case KEY_RIGHT:
    moveBlockRight();
    break;
  case KEY_DOWN:
    moveBlockDown();
    giveScoreForManualDrop();
    break;

  case KEY_Z:
    rotateBlockBackward();
    break;
  case KEY_X:
    rotateBlockForward();
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

  if (!blockWasMoved && !gameOver) {
    lockBlockAndSpawnNextBlock();

    int poppedRows = grid.popFullRows();
    giveScoreForFullRows(poppedRows);
  }
}

void Game::giveScoreForFullRows(int fullRows) {
  switch (fullRows) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 300;
    break;
  case 3:
    score += 500;
    break;
  case 4:
    score += 800;
    break;
  default:
    break;
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

  if (!blockFits()) {
    gameOver = true;
  }

  nextBlock = popRandomBlock();
}

void Game::restart() {
  gameOver = false;

  grid.initialize();
  blocks = getDefaultBlocks();
  currentBlock = popRandomBlock();
  nextBlock = popRandomBlock();
}

void Game::drawGrid() {
  const int BORDER_WIDTH = 1;

  auto gridCells = grid.getGrid();

  for (int row = 0; row < grid.NUM_ROWS; row++) {
    for (int column = 0; column < grid.NUM_COLUMNS; column++) {
      int cellValue = gridCells[row][column];

      DrawRectangle(column * CELL_SIZE + PADDING_SIZE,
                    row * CELL_SIZE + PADDING_SIZE, CELL_SIZE - BORDER_WIDTH,
                    CELL_SIZE - BORDER_WIDTH, getCellColor(cellValue));
    }
  }
}
