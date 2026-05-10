class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; i++) dp[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = abs(nums[j] - nums[i]);
                if (diff <= target) {
                    // edge case
                    if (!(j != 0 && dp[j] == 0))
                        dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1] > 0 ? dp[n-1] : -1;
    }
};
