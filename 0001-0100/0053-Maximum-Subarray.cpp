class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currmax = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] > sum) {
                sum = nums[i];
            }
            currmax = max(currmax, sum);
        }
        return currmax;
    }
};
