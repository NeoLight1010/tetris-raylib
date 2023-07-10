#include "block.h"
#include "colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block(){};

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
