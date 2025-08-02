class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> dp(1 << 17, 0);
        int maxi = 0;
        dp[0] = 1;
        for (int num : nums) {
            for (int i = maxi; i >= 0; i--) {
                dp[i | num] += dp[i];
            }
            maxi = maxi | num;
        }
        return dp[maxi];
    }
};
