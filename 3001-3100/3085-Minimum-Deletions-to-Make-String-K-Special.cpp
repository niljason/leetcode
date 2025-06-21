class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); i++) {
            freq[word[i]-'a'] += 1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < 26; i++) {
            int curr = freq[i];
            int sum = 0;
            for (int j = 0; j < 26; j++) {
                if (freq[j] < curr) {
                    sum += freq[j];
                }
                else if (freq[j] > curr + k) {
                    sum += (freq[j] - curr - k);
                }
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};
