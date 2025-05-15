class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> results;
        int bit = groups[0];
        results.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (bit != groups[i]) {
                results.push_back(words[i]);
                bit = groups[i];
            }
        }
        return results;
    }
};
