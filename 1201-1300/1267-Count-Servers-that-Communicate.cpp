class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        vector<int> rowComps(numRows, 0);
        vector<int> colComps(numCols, 0);

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid[row][col] == 1) {
                    rowComps[row]++;
                    colComps[col]++;
                }
            }
        }

        int totalComps = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid[row][col] == 1 && (rowComps[row] > 1 || colComps[col] > 1)) {
                    totalComps++;
                } 
            }
        }
        return totalComps;
    }
};
