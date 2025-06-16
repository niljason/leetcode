class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int currMin = nums[0];
        maxDiff = max(nums[1] - currMin, maxDiff);
        for (int i = 1; i < nums.size()-1; i++) {
            currMin = min(currMin, nums[i]);
            maxDiff = max(nums[i+1] - currMin, maxDiff);
        }
        return maxDiff != 0 ? maxDiff : -1;
    }
};
