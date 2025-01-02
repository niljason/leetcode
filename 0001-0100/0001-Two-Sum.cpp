class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int ind = 0; ind < nums.size(); ++ind) {
            auto it = mp.find(target - nums[ind]);
            if (it != mp.end()) {
                return {it->second, ind};
            }
            mp.insert({nums[ind], ind});
        }
        return {};
    }
};
