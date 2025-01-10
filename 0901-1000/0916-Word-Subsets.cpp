class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> maxFreq(26, 0);
        for (string& words: words2) {
            vector<int> freq(26,0);
            for (char c: words) {
                freq[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> universal;
        for (string& words: words1) {
            vector<int> freq(26, 0);
            for (char c: words) {
                freq[c-'a']++;
            }
            bool add = true;
            for (int i = 0; i < 26; i++) {
                if (maxFreq[i] != 0 && maxFreq[i] > freq[i]) { add = false; }
            }
            if (add) { universal.push_back(words); }
        }
        return universal;
    }
};
