class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int curr_max = abs(nums[0] - nums[nums.size()-1]);
        for (int i = 0; i < nums.size()-1; i++)  {
            curr_max = max(curr_max, abs(nums[i] - nums[i+1]));
        }
        return curr_max;
    }
};
