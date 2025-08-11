class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int start = 1;
        int MOD = 1000000007;
        vector<int> powers;
        for (int i = 1; i < 32; i++) {
            if (n & start) { powers.push_back(start % MOD); }
            start = start << 1;
        }

        vector<vector<int>> dp(powers.size(), vector<int>(powers.size()));
        for (int i = 0; i < powers.size(); i++) {
            int cur = 1;
            for (int j = i; j < powers.size(); j++) {
                cur = static_cast<long long>(cur) * powers[j] % MOD;
                dp[i][j] = cur;
            }
        }
        vector<int> answers;
        for (auto & query : queries) {
            answers.push_back(dp[query[0]][query[1]]);
        }
        return answers;
    }
};
