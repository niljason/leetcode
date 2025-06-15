class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        for (int num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        int r = 0;
        while (maxi % mini != 0) {
            r = maxi % mini;
            maxi = mini;
            mini = r;
        }
        return mini;
    }
};
