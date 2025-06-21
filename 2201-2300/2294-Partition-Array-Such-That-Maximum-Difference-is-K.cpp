class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int total = 1;
        int curr = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - curr > k) {
                total++;
                curr = nums[i];
            }
        }
        return total;
    }
};
