class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
            if (map.find(num) != map.end()) { return true; } 
            else { map[num] = 1; }
        }
        return false;
    }
};
