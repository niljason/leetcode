class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (map.find(num) == map.end()) {
                map[num] = i;
            } 
            else if (i - map[num] <= k) { return true; }
            map[num] = i;
        }
        return false;
    }
};
