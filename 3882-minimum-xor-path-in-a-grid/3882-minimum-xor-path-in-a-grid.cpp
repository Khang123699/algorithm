class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalColumns = grid[0].size();
        int maxXorLimit = 1024;
        
        vector<vector<bool>> reachableXor(totalColumns, vector<bool>(maxXorLimit, false));
        
        int initialXorValue = grid[0][0];
        reachableXor[0][initialXorValue] = true;
        
        for (int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
            for (int columnIndex = 0; columnIndex < totalColumns; columnIndex++) {
                if (rowIndex == 0 && columnIndex == 0) {
                    continue;
                }
                
                int currentCellValue = grid[rowIndex][columnIndex];
                vector<bool> currentCellXor(maxXorLimit, false);
                
                if (rowIndex > 0) {
                    for (int xorValue = 0; xorValue < maxXorLimit; xorValue++) {
                        if (reachableXor[columnIndex][xorValue]) {
                            int nextXorValue = xorValue ^ currentCellValue;
                            currentCellXor[nextXorValue] = true;
                        }
                    }
                }
                
                if (columnIndex > 0) {
                    for (int xorValue = 0; xorValue < maxXorLimit; xorValue++) {
                        if (reachableXor[columnIndex - 1][xorValue]) {
                            int nextXorValue = xorValue ^ currentCellValue;
                            currentCellXor[nextXorValue] = true;
                        }
                    }
                }
                
                reachableXor[columnIndex] = currentCellXor;
            }
        }
        
        for (int xorValue = 0; xorValue < maxXorLimit; xorValue++) {
            if (reachableXor[totalColumns - 1][xorValue]) {
                return xorValue;
            }
        }
        
        return 0;
    }
};