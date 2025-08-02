class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) { count++; }
            else if (nums[i] > maxi) { count = 1; maxi = nums[i]; maxCount = 0;}
            else { count = 0; }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
