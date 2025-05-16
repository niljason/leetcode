class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        pair<int, int> best = {-1, -1};

        for (int i = n-1; i >= 0; i--) {
            pair <int, int> curr_best = {-1, -1};

            for (int j = i; j < n; j++) 
            {
                if (hamming(words[i], words[j]) && groups[i] != groups[j])
                {
                    if (dp[j] > curr_best.first) {
                        curr_best.first = dp[j];
                        curr_best.second = j;
                    }
                }
            }
            dp[i] = max(dp[i], curr_best.first + 1);
            prev[i] = curr_best.second;
            if (dp[i] > best.first) 
            {
                best.first = dp[i];
                best.second = i;
            }
        }

        vector<string> results;
        int ind = best.second;
        while (ind != -1) {
            results.push_back(words[ind]);
            ind = prev[ind];
        }
        return results;
    }

    bool hamming(string& word1, string& word2) {
        int count = 0;
        if (word1.size() != word2.size()) { return false; }
        for (int i = 0; i < word1.size(); i++) 
        {
            if (word1[i] != word2[i]) { count++; }
        }
        return count == 1;
    } 
};

