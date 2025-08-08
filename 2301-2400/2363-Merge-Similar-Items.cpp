class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> mp(1001, 0);
        for (int i = 0; i < items1.size(); i++) {
            mp[items1[i][0]] += items1[i][1];
        }
        for (int i = 0; i < items2.size(); i++) {
            mp[items2[i][0]] += items2[i][1];
        }
        vector<vector<int>> result;
        for (int i = 1; i <= 1000; i++) {
            if (mp[i] > 0) {
                result.push_back({i, mp[i]});
            }
        }
        return result;
    }
};
