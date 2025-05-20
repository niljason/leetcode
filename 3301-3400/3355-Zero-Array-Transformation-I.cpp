class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> start(nums.size());
        vector <int> end(nums.size());
        for (int i = 0; i < queries.size(); i++) {
            start[queries[i][0]]++;
            end[queries[i][1]]++;
        }
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += start[i];
            if (nums[i] > total) { return false; }
            total -= end[i];
        }
        return true;
    }
};
