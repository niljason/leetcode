class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            // scan left
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            int left = 0;
            int right = 0;
        
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] != nums[i]) {
                    left = nums[j];
                    break;
                }
            }
            // scan right
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] != nums[i]) {
                    right = nums[j];
                    break;
                }
            }

            if (left > nums[i] && right > nums[i]) { res++; }
            if (left != 0 && right != 0 && left < nums[i] && right < nums[i]) { res++; }
        }
        return res;
    }
};
