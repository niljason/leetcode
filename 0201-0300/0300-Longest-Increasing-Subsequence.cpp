class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        int maxy = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
            maxy = max(maxy, dp[i]);
        }

        return maxy;
    }
};
