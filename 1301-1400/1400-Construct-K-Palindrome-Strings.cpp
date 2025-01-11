class Solution {
public:
    bool canConstruct(string s, int k) {
        // each letter is used once and so cannot be possible to have more than length of string
        if (k > s.size()) { return false; }
        vector<int> occurences(26, 0);
        for (char c : s) {
            occurences[c-'a']++;
        }
        // if a letter has odd number occurence it itself has to be used in a palindrome of odd length
        // this implies to construct palindromes out of everything there is at least odd of them
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (occurences[i] % 2 == 1) { odd++; }
        }
        // so if odd > k then it is not possible to do it with k or less
        return (odd <= k);
    }
};
