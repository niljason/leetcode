class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> results(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < results[i].size(); j++) {
                if (i == 0 && j == 0) { results[i][j] = grid[i][j]; }
                else if (i == 0) { results[i][j] = results[i][j-1] + grid[i][j]; }
                else if (j == 0) { results[i][j] = results[i-1][j] + grid[i][j]; }
                else { results[i][j] = min(results[i-1][j] + grid[i][j], results[i][j-1] + grid[i][j]); }
            }
        }
        return results[results.size()-1][results[0].size()-1];
    }
};
