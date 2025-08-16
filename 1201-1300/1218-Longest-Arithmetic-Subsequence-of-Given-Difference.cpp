class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxSub = 0;
        unordered_map<int, int> mp;
        vector<int> dp(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            auto it = mp.find(arr[i] - difference);
            if (it != mp.end()) { dp[i] = dp[it->second] + 1; }
            else { dp[i] = 1; }
            mp[arr[i]] = i;
            maxSub = max(maxSub, dp[i]);
        }
        return maxSub;
    }
};
