class Solution {
public:
    int maximumLength(vector<int>& nums) {
        bool flip = nums[0] % 2;
        int count = 1;
        int odd = flip ? 1 : 0;
        int even = flip ? 0 : 1;
        for (int i = 1; i < nums.size(); i++) {
            if (flip != nums[i] % 2) {
                flip = !flip;
                count++;
            }
            if (nums[i] % 2 == 1) { odd++; }
            if (nums[i] % 2 == 0) { even++; }
        }
        return max(count, max(odd, even));
    }
};
