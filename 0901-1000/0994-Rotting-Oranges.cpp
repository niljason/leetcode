class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int moves = -1;
        int oranges = 0;
        queue<pair<int, int>> list;
        for (int rows = 0; rows < grid.size(); ++rows) {
            for (int cols = 0; cols < grid[rows].size(); ++cols) {
                if (grid[rows][cols] == 2) { 
                    list.push(make_pair(rows, cols));
                }
                if (grid[rows][cols] != 0) oranges++;
            }
        }

        if (oranges == 0) return 0;

        while (!list.empty()) {
            int curr_size = list.size();
            for (int ind = 0; ind < curr_size; ++ind) {
                
                pair<int, int> coor = list.front();
                int row = coor.first;
                int col = coor.second;
                list.pop();

                if (row > 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    list.push(make_pair(row-1, col));
                }
                if (row != grid.size()-1 && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    list.push(make_pair(row+1, col));
                }
                if (col > 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    list.push(make_pair(row, col-1));
                }
                if (col != grid[row].size()-1 && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    list.push(make_pair(row, col+1));
                }
            }
            moves++;    
        }

        for (int rows = 0; rows < grid.size(); ++rows) {
            for (int cols = 0; cols < grid[rows].size(); ++cols) {
                if (grid[rows][cols] == 1) { 
                    return -1;
                }
            }
        }

        return moves;
    }
};
