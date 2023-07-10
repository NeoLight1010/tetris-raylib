#include <raylib.h>
#include <vector>

class Grid {
public:
  static const int NUM_ROWS = 20;
  static const int NUM_COLUMNS = 10;
  static const int CELL_SIZE = 30;
  static const int EMPTY_CELL_VALUE = 0;

  Grid();
  void debugPrint();
  void draw();
  void initialize();

  bool isCellEmpty(int row, int column);
  bool isCellOutside(int row, int column);

  void popFullRows();

  void setCellValue(int row, int column, int value);

private:
  int grid[NUM_ROWS][NUM_COLUMNS];

  bool isRowFull(int row);
  void popRow(int row);
  void clearRow(int row);
  void moveDownRowsAbove(int row);
};
