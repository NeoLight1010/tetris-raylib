#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>
#include <vector>

Grid::Grid() { initializeGrid(); }

void Grid::initializeGrid() {
  for (int row = 0; row < NUM_ROWS; row++) {
    for (int column = 0; column < NUM_COLUMNS; column++) {
      grid[row][column] = 0;
    }
  }
}

void Grid::debugPrint() {
  for (int row = 0; row < NUM_ROWS; row++) {
    for (int column = 0; column < NUM_COLUMNS; column++) {
      std::cout << grid[row][column] << " ";
    }

    std::cout << std::endl;
  }
}

void Grid::draw() {
  const int padding = 1;

  for (int row = 0; row < NUM_ROWS; row++) {
    for (int column = 0; column < NUM_COLUMNS; column++) {
      int cellValue = grid[row][column];

      DrawRectangle(column * CELL_SIZE + padding, row * CELL_SIZE + padding,
                    CELL_SIZE - padding, CELL_SIZE - padding,
                    getCellColor(cellValue));
    }
  }
}

bool Grid::isCellEmpty(int row, int column) {
  return grid[row][column] == EMPTY_CELL_VALUE;
}

bool Grid::isCellOutside(int row, int column) {
  return row < 0 || row >= NUM_ROWS || column < 0 || column >= NUM_COLUMNS;
}

void Grid::popFullRows() {
  for (int row = 0; row < NUM_ROWS; row++) {
    if (isRowFull(row)) {
      popRow(row);
    }
  }
}

bool Grid::isRowFull(int row) {
  for (int cellValue : grid[row]) {
    if (cellValue == EMPTY_CELL_VALUE) {
      return false;
    }
  }

  return true;
}

void Grid::popRow(int row) {
  clearRow(row);
  moveDownRowsAbove(row);
}

void Grid::clearRow(int row) {
  for (int column = 0; column < NUM_COLUMNS; column++) {
    setCellValue(row, column, EMPTY_CELL_VALUE);
  }
}

void Grid::moveDownRowsAbove(int row) {
  for (int rowToMove = row - 1; rowToMove >= 0; rowToMove--) {
    for (int column = 0; column < NUM_COLUMNS; column++) {
      int valueToMove = grid[rowToMove][column];
      setCellValue(rowToMove + 1, column, valueToMove);
    }
  }
}

void Grid::setCellValue(int row, int column, int value) {
  grid[row][column] = value;
}
