class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowMap, colMap;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && rowMap.count(board[i][j])) { return false; }
                rowMap.insert(board[i][j]);
                                
                if (board[j][i] != '.' && colMap.count(board[j][i])) { return false; }
                colMap.insert(board[j][i]);
            }
        }


        for (int quad = 0; quad < 9; quad++) {
            int rowStart = (quad%3)*3;
            int colStart = (quad/3)*3;
            unordered_set<char> gridMap;
            for (int r = rowStart; r < rowStart+3; r++) {
                for (int c = colStart; c < colStart+3; c++) {
                    if (board[r][c] != '.' && gridMap.count(board[r][c])) { return false; }
                    gridMap.insert(board[r][c]);
                }
            }
        }
        return true;
    }
    
};
