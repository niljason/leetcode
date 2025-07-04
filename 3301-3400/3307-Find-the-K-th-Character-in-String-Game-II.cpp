class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) { return 'a'; }
        k--;
        vector<int> nums;
        while (k != 0) {
            nums.push_back(k%2);
            k /= 2;
        }
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++ ) {
            if (nums[i] == 1 && operations[i] == nums[i] == 1) {
                count++;
            }
        }
        return 'a' + count%26;
    }
};
