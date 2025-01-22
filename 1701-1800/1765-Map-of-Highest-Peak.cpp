class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int numRows = isWater.size();
        int numCols = isWater[0].size();
        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
        vector<vector<int>> grid(numRows, vector<int>(numCols, 0));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (isWater[row][col] == 1) {
                    visited[row][col] = true;
                    nodes.push({row, col});
                }
            }
        }

        int time = 1;
        while (!nodes.empty()) {
            int count = nodes.size();
            for (int i = 0; i < count; i++) {
                pair<int, int> curr = nodes.front();
                nodes.pop();
                
                for (const auto& dir: directions) {
                    int newRow = curr.first + dir.first;
                    int newCol = curr.second + dir.second;

                    if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                        grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                        nodes.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                        grid[newRow][newCol] = time;
                    }
                }

            }
            time++;
        }
        return grid;
    }
};
