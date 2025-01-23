class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique;
        unordered_set<int> visited;
        int maxCount = 0;
        int currCount = 0;
        for (int num: nums) {
            unique.insert(num);
        }
        for (auto iter = unique.begin(); iter != unique.end(); iter++) {
            int val = *iter;
            if (visited.count(val)) { continue; }
            while (unique.count(val)) { val--; }   
            val++;
            while (unique.count(val)) { 
                currCount++; 
                visited.insert(val);
                val++;
            }
            maxCount = max(maxCount, currCount);
            currCount = 0;
        }
        return maxCount;
    }
};
