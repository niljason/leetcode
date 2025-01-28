class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        vector<vector<int>> directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        int rows = grid.size();
        int cols = grid[0].size();

        int currVal = 0;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(r, c));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (!visited[curr.first][curr.second]) {
                visited[curr.first][curr.second] = true;
                if (grid[curr.first][curr.second] > 0) {
                    currVal += grid[curr.first][curr.second];
                    for (auto dir : directions) {
                        int x = curr.first + dir[0];
                        int y = curr.second + dir[1];
                        if (x >= 0 && x < rows && y >= 0 && y < cols) {
                            q.push(pair<int, int>(x, y));
                        }
                    }
                }
            }
        }
        return currVal;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxFish = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j]) { continue; }
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(grid, visited, i, j));
                }
            }
        }
        return maxFish;
    }
};
