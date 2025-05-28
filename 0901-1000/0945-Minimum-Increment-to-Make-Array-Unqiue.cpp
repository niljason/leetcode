class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for (int ind = 1; ind < nums.size(); ++ind) {
            if (prev >= nums[ind]) {
                moves += (prev - nums[ind]) + 1;
                nums[ind] = prev+1;
            }
            prev = nums[ind];
        }
        return moves;
    }
};
