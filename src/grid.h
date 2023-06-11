#include <vector>
#include <raylib.h>

class Grid {
    public:
        int grid[20][10];

        Grid();
        void debugPrint();
        void draw();

    private:
        int numRows = 20;
        int numColumns = 10;
        int cellSize = 30;

        std::vector<Color> cellColors = std::vector<Color>();

        void initializeGrid();
        void initializeCellColors();
};
