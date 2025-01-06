class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (start[c] == -1) { start[c] = i; }
            else { end[c] = i; }
        }
        
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (start[i] == -1 || end[i] == -1) continue;
            unordered_set<char> amt;
            for (int j = start[i]+1; j < end[i]; j++) {
                amt.insert(s[j]);
            }
            total += amt.size();
        }
        return total;
    }
};
