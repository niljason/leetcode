class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int left = 0; // inclusive
        int right = 1; // exclusive
        int currScore = nums[left];
        int maxScore = currScore;
        mp[nums[left]] = 1; // use one-based indexing instead of dealing with find
        while (right != nums.size()) {
            // element exists
            if (mp[nums[right]] > 0 && mp[nums[right]] > left) {
                while (mp[nums[right]] > left) {
                    currScore -= nums[left];
                    left++;
                }
            }
            currScore += nums[right];
            maxScore = max(maxScore, currScore);
            mp[nums[right]] = right+1;
            right++;
        }
        return maxScore;
    }
};
