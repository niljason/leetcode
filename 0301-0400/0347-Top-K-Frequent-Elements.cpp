bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        vector<pair<int, int>> freq(map.begin(), map.end());

        sort(freq.begin(), freq.end(), comp);

        int numSize = freq.size();
        vector<int> topFreq;

        for (int i = 0; i < k; i++) {
            topFreq.push_back(freq[i].first);
        }
        return topFreq;
    }
};
