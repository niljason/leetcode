class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxWindow = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { zeroCount++; }
            while (zeroCount > 1) {
                if (nums[left] == 0) { zeroCount--; }
                left++;
            }
            maxWindow = max(maxWindow, i-left);
        }
        return maxWindow;
    }
};
