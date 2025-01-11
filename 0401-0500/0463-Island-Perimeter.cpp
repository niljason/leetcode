class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == 1) {
                    perimeter += countBorders(grid, x, y);
                }
            }
        }
        return perimeter;
    }

    int countBorders(vector<vector<int>>& grid, int x, int y) {
        int borders = 0;
        if (x-1 >= 0 && grid[x-1][y] == 0 || x-1 < 0)  { borders++; }
        if (x+1 < grid.size() && grid[x+1][y] == 0 || x+1 == grid.size()) { borders++; } 
        if (y-1 >= 0 && grid[x][y-1] == 0 || y-1 < 0) { borders++; }
        if (y+1 < grid[x].size() && grid[x][y+1] == 0 || y+1 == grid[x].size()) { borders++; }
        return borders;
    }
};
