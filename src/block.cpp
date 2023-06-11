#include "block.h"
#include "colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block(){};

void Block::draw() {
  std::vector<Position> currentRotationCells = cells[rotationState];

  for (Position cell : currentRotationCells) {
    DrawRectangle(cell.column * cellSize + 1, cell.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, getCellColor(id()));
  }
}
