class Solution {
public:
    int minimumLength(string s) {
        int length = s.size();
        vector<int> freq(26, 0);
        for (char c: s) {
            freq[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 3 && freq[i] % 2 == 1) {
                length -= (freq[i] - 1);
            }
            if (freq[i] >= 3 && freq[i] % 2 == 0) {
                length -= (freq[i] - 2);
            }
        }
        return length;
    }
};
