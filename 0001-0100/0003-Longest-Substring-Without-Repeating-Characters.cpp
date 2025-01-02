class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dict;
        int maxy = 0;
        int start = -1;
        for (int c = 0; c < s.size(); ++c) {
            if (dict.find(s[c]) != dict.end()) {
                start = max(start, dict[s[c]]);
            }
            dict[s[c]] = c;
            maxy = max(maxy, c - start);
        }
        return maxy;
    }
};
