class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> results;
        for (int i = 0; i < s.size(); i += k) {
            results.push_back(s.substr(i, k));
        }
        int fillCount = k - results[results.size()-1].size();
        results[results.size()-1] += string(fillCount, fill);
        return results;
    }
};
