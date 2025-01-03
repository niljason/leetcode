class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int x;
        int prior = 0;
        int val = 0;
        for (int ind = s.size()-1; ind >= 0; --ind) {
            x = mp[s[ind]];
            if (x < prior) {
                val -= x;
            } else {
                val += x;
            }
            prior = x;
        }
        return val;
    }
};
