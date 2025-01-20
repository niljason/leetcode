class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        
        unordered_map<int, pair<int, int>> map;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int val = mat[row][col];
                map[val] = {row, col};
            }
        }

        vector<int> paintedRows(numRows, numCols);
        vector<int> paintedCols(numCols, numRows);
        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> keyPair = map[arr[i]];
            paintedRows[keyPair.first]--;
            paintedCols[keyPair.second]--;
            if (paintedRows[keyPair.first] == 0 || paintedCols[keyPair.second] == 0) { return i; }
        }

        return -1;
    }
};
