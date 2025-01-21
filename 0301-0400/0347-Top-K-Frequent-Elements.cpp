struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; 
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq(map.begin(), map.end());

        int numSize = pq.size();
        vector<int> topFreq;

        for (int i = 0; i < k; i++) {
            pair<int, int> curr = pq.top();
            pq.pop();
            topFreq.push_back(curr.first);
        }
        return topFreq;
    }
};

