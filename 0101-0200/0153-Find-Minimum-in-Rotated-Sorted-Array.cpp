class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (left + 1 == right) { return min(nums[left], nums[right]); }
            if (nums[right] > nums[mid]) {
                right = mid;
            }
            else if(nums[left] < nums[mid]) {
                left = mid;
            }
        }
        return nums[left];
    }
};
