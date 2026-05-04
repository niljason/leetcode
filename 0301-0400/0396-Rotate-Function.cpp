class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int start_sum = 0;
        int nums_sum = 0;
        for (int i = 0; i < n; i++) {
            start_sum += (i * nums[i]);
            nums_sum += nums[i];
        }
        int maxi = start_sum;
        for (int i = 1; i < n; i++) {
            start_sum = start_sum + (nums_sum - nums[n-i]*n);
            maxi = max(maxi, start_sum);
        }
        return maxi;
    }
};
