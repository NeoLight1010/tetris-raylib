#include "block.h"
#include "colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block(){};

void Block::draw() {
  std::vector<Position> currentRotationCells = rotations[rotationState];

  for (Position cell : getMovedCellPositions()) {
    DrawRectangle(cell.column * cellSize + 1, cell.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, getCellColor(id()));
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
