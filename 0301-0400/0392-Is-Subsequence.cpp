class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t) { return true; }
        int slow = 0;
        int fast = 0;
        while (fast < t.size()) {
            if (s[slow] == t[fast]) { slow++; }
            if (slow == s.size()) { return true; }
            fast++;
        }
        return false;
    }
};
