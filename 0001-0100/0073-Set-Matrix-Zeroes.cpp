class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool row = false;
        bool col = false;

        // for row0 and col0 since we store info there
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) { col = true; break; } 
        }
        for (int j = 0; j < c; j++) {
            if (matrix[0][j] == 0) { row = true; break; }
        }

        // set flag to 0 since that's what we set it to in the end anyways
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // for every row except row 0 and col 0
        for (int i = 1; i < r; i++) 
        {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < c; j++) matrix[i][j] = 0;
            }
        }
        // for every column except col 0 and row 0
        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < r; i++) matrix[i][j] = 0;
            }
        }
        // do row 0 and col 0
        if (row) {
            for (int j = 0; j < c; j++) matrix[0][j] = 0;
        }
        if (col) {
            for (int i = 0; i < r; i++) matrix[i][0] = 0;
        }
    }
};
