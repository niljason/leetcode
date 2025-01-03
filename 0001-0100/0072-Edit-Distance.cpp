class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()+1;
        int n = word2.size()+1;
        int matrix[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }

        for (int i = 1; i < m; ++i) {
            matrix[i][0] = i;
        }

        for (int j = 1; j < n; ++j) {
            matrix[0][j] = j;
        }
        int sub = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    sub = 0;
                } else { sub = 1; }
                matrix[i][j] = std::min({matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1] + sub});
            }
        }

        return matrix[m-1][n-1];
    }
};
