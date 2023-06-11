#include "grid.h"
#include <iostream>
#include <raylib.h>
#include <vector>

Grid::Grid() {
  initializeGrid();
  initializeCellColors();
}

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
                    cellColors[cellValue]);
    }
  }
}

void Grid::initializeCellColors() {
  Color darkGrey = {26, 31, 40, 255};
  Color green = {47, 230, 23, 255};
  Color red = {232, 18, 18, 255};
  Color orange = {226, 116, 17, 255};
  Color yellow = {237, 234, 4, 255};
  Color purple = {166, 0, 247, 255};
  Color cyan = {21, 204, 209, 255};
  Color blue = {13, 64, 216, 255};

  cellColors = {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
