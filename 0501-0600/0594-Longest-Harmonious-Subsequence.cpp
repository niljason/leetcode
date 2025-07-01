class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (const auto& [key, value] : mp) {
            auto minus = mp.find(key-1);
            auto add = mp.find(key+1);
            if (minus != mp.end()) {
                maxi = max(maxi, value + minus->second);
            }
            if (add != mp.end()) {
                maxi = max(maxi, value + add->second);
            }
        }
        return maxi;
    }
};
