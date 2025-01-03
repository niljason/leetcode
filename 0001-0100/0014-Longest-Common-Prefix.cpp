class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortest = strs[0];
        for (string words : strs) {
            if (words.size() < shortest.size()) {
                shortest = words;
            }
        }
        for (int i = 0; i < shortest.size()+1; i++) {
            string sub = shortest.substr(0,i);
            for (string words: strs) {
                if (sub != words.substr(0,i)) {
                    return shortest.substr(0,i-1);
                }
            }
        }
        return shortest;
    }
};
