class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev = nums[0];
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                if (flag) { return false;}
                flag = true;
                // if true we remove i-1, otherwise remove i as the problem by not updating prev to new i
                if (i == 1 || nums[i] > nums[i-2]) { prev = nums[i]; }
            }
            else {
                prev = nums[i];
            }
        }
        return true;
    }
};
