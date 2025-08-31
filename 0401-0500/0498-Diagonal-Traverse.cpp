class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> mp(m+n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        for (int d = 0; d < mp.size(); d++) {
            if (d % 2 == 0) {
                reverse(mp[d].begin(), mp[d].end());
            }
            res.insert(res.end(), mp[d].begin(), mp[d].end());
        }
        return res;
    }
};
