class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // cols
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        vector<int> result;
        int currDir = 0;
        int x = 0; // cols
        int y = 0; // rows
        int count = m*n; // number of items
        while (count > 0) {
            result.push_back(matrix[y][x]);
            visited[y][x] = true;
            int newX = x+directions[currDir%4][1];
            int newY = y+directions[currDir%4][0];
            int tempCount = 0;
            while (newX == -1 || newY == -1 || newX == n || newY == m || visited[newY][newX]) {
                currDir++;
                newX = x+directions[currDir%4][1];
                newY = y+directions[currDir%4][0];
                tempCount++;
                if (tempCount == 3) { break; }
            }
            x = newX;
            y = newY;
            count--;
        }
        return result;
    }
};
