class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalColumns = grid[0].size();
        int closedIslandCount = 0;
        vector<int> rowDirections = {-1, 1, 0, 0};
        vector<int> columnDirections = {0, 0, -1, 1};
        for (int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
            for (int columnIndex = 0; columnIndex < totalColumns; columnIndex++) {
                if (grid[rowIndex][columnIndex] == 0) {
                    bool isClosed = true;
                    queue<pair<int, int>> cellQueue;
                    cellQueue.push({rowIndex, columnIndex});
                    grid[rowIndex][columnIndex] = 1;
                    while (!cellQueue.empty()) {
                        auto [currentRow, currentColumn] = cellQueue.front();
                        cellQueue.pop();
                        if (currentRow == 0 || currentRow == totalRows - 1 || currentColumn == 0 || currentColumn == totalColumns - 1) {
                            isClosed = false;
                        }
                        for (int directionIndex = 0; directionIndex < 4; directionIndex++) {
                            int nextRow = currentRow + rowDirections[directionIndex];
                            int nextColumn = currentColumn + columnDirections[directionIndex];
                            if (nextRow >= 0 && nextRow < totalRows && nextColumn >= 0 && nextColumn < totalColumns) {
                                if (grid[nextRow][nextColumn] == 0) {
                                    grid[nextRow][nextColumn] = 1;
                                    cellQueue.push({nextRow, nextColumn});
                                }
                            }
                        }
                    }
                    if (isClosed) {
                        closedIslandCount++;
                    }
                }
            }
        }
        return closedIslandCount;
    }
};