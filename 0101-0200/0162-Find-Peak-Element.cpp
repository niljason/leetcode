class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = (right - left)/2 + left;
            int midValue = nums[mid];
            int leftValue = (mid-1 >= 0) ? nums[mid-1] : INT_MIN; 
            int rightValue = (mid+1 != nums.size()) ? nums[mid+1] : INT_MIN;
            if (midValue > leftValue && midValue > rightValue) { return mid; }
            if (leftValue > midValue) { right = mid-1; }
            else { left = mid+1; }
        }
        return 0;
    }
};
