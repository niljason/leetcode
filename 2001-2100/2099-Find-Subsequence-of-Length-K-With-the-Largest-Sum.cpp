class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> values;
        for (int i = 0; i < nums.size(); i++) {
            values.emplace_back(i, nums[i]);
        }
        sort(values.begin(), values.end(),
            [](auto a, auto b) { return a.second > b.second; }
        );
        sort(values.begin(), values.begin()+k);
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(values[i].second);
        }
        return result;
    }
};
