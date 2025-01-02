class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        vector<vector<int>> table(len, vector<int>(len));

        string result = "";

        for (int i = 0; i < len; i++) {a
            for (int j = 0; j < len; j++) {
                if (i == j) { table[i][j] = 1; }
                else if (i < j) { table[i][j] = 0; }
                else if (s[i] == s[j]) {
                    table[i][j] = table[i-1][j+1] + 2;
                    if ((i-j+1) != table[i][j]) {
                        table[i][j] = 0;
                    }
                }
                else { table[i][j] = 0; }
                if (i >= j && table[i][j] > result.size()) {
                    result = s.substr(j, table[i][j]);
                }
            }
        }
        return result;
    }
};
