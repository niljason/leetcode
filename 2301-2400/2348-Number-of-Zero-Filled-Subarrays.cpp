class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarrays = 0;
        int count = 0;
        for (int i : nums) {
            if (i == 0) { count++; }
            else { count = 0; }
            subarrays += count;
        }
        return subarrays;
    }
};
