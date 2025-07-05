class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (compareTwo(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

    bool compareTwo(string& word1, string& word2) {
        vector<bool> letters1(26, false);
        vector<bool> letters2(26, false);
        for (char c : word1) {
            letters1[c-'a'] = true;
        }
        for (char c : word2) {
            letters2[c-'a'] = true;
        }

        for (int i = 0; i < 26; i++) {
            if (letters1[i] ^ letters2[i]) {
                return false;
            }
        }
        return true;
    }
};
