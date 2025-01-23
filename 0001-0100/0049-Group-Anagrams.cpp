class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> dict;
        for (string& str: strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            if (dict.find(sorted) == dict.end()) {
                dict[sorted] = dict.size();
                vector<string> temp = {str};
                result.push_back(temp);
            } else {
                int ind = dict[sorted];
                result[ind].push_back(str);
            }
        }
        return result;
    }
};
