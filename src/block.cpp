#include "block.h"
#include "colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block(){};

void Block::draw() {
  const int BORDER_WIDTH = 1;

  std::vector<Position> currentRotationCells = rotations[rotationState];

  for (Position cell : getMovedCellPositions()) {
    DrawRectangle(cell.column * cellSize + 10, cell.row * cellSize + 10,
                  cellSize - BORDER_WIDTH, cellSize - BORDER_WIDTH,
                  getCellColor(id()));
  }
}

void Block::move(int rows, int columns) {
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::getMovedCellPositions() {
  std::vector<Position> movedCellPositions = {};

  for (Position cell : rotations[rotationState]) {
    movedCellPositions.push_back(
        Position{cell.row + rowOffset, cell.column + columnOffset});
  }

  return movedCellPositions;
};

int Block::id() { return 0; }

void Block::center() { move(0, 3); }

void Block::rotateForward() {
  rotationState = (rotationState + 1) % rotations.size();
}

void Block::rotateBackward() {
  rotationState = (rotationState - 1) % rotations.size();
}
