class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> table(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        table[0][0] = 0;
        while (true) {
            vector<vector<int>> prev = table;

            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[row].size(); col++) {
                    // can check above
                    if (row > 0) {
                        table[row][col] = min(table[row][col], table[row-1][col]+(grid[row-1][col] == 3 ? 0:1));
                    }
                    // can check left
                    if (col > 0) {
                        table[row][col] = min(table[row][col], table[row][col-1]+(grid[row][col-1] == 1 ? 0:1));  
                    }
                }
            }

            for (int row = grid.size()-1; row >= 0; row--) {
                for (int col = grid[row].size()-1; col >= 0; col--) {
                    if (row < grid.size()-1) {
                        table[row][col] = min(table[row][col], table[row+1][col] + (grid[row+1][col] == 4 ? 0:1));
                    }
                    if (col < grid[row].size()-1) {
                        table[row][col] = min(table[row][col], table[row][col+1] + (grid[row][col+1] == 2 ? 0:1));
                    }
                }
            }
            if (prev == table) {
                break;
            }
        }
        return table[grid.size()-1][grid[0].size()-1];
    }
};
