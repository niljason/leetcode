class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int ind = 0;
        while (ind <= right) {
            if (nums[ind] == 0) {
                swap(nums[ind], nums[left]);
                left++;
            }
            if (nums[ind] == 2) {
                swap(nums[ind], nums[right]);
                right--;
                --ind;
            }
            ++ind;
        }
        
    }
};
