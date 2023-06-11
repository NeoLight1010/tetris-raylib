#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>
#include <vector>

Grid::Grid() { initializeGrid(); }

void Grid::initializeGrid() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numColumns; column++) {
      grid[row][column] = 0;
    }
  }
}

void Grid::debugPrint() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numColumns; column++) {
      std::cout << grid[row][column] << " ";
    }

    std::cout << std::endl;
  }
}

void Grid::draw() {
  const int padding = 1;

  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numColumns; column++) {
      int cellValue = grid[row][column];

      DrawRectangle(column * cellSize + padding, row * cellSize + padding,
                    cellSize - padding, cellSize - padding,
                    getCellColor(cellValue));
    }
  }
}
