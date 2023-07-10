#include "grid.h"
#include "colors.h"
#include <array>
#include <iostream>
#include <raylib.h>
#include <vector>

Grid::Grid() { initialize(); }

void Grid::initialize() {
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

std::array<std::array<int, Grid::NUM_COLUMNS>, Grid::NUM_ROWS> Grid::getGrid() {
  return grid;
}
