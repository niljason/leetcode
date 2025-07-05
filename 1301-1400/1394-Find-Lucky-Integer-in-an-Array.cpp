class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        int maxi = -1;
        for (auto& val : mp) {
            if (val.first == val.second) {
                maxi = max(maxi, val.first);
            }
        }

        return maxi;
    }
};
