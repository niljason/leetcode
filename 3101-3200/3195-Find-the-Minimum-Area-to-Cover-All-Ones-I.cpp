class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = grid.size();
        int maxX = 0;
        int minY = grid[0].size();
        int maxY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};
