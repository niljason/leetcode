class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int numCols = grid[0].size();
        vector<vector<long>> sums(2, vector<long>(numCols, 0));
        sums[0][0] = grid[0][0];
        sums[1][numCols-1] = grid[1][numCols-1];

        for (int i = 1; i < numCols; i++) {
            sums[0][i] = grid[0][i] + sums[0][i-1];
            sums[1][numCols-1-i] = grid[1][numCols-1-i] + sums[1][numCols-i];
        }

        long minimum = LONG_MAX;
        for (int i = 0; i < numCols; i++) {
            long top = sums[0][numCols-1] - sums[0][i];
            long bot = sums[1][0] - sums[1][i];
            minimum = min(minimum, max(top, bot));
        }

        return minimum;
    }
};
