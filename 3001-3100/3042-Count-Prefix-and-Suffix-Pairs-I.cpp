class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (isPrefixandSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

    bool isPrefixandSuffix(string& word1, string& word2) {
        if (word1.size() > word2.size()) { return false; }
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] == word2[i] && word1[word1.size()-1-i] == word2[word2.size()-1-i]) { continue; }
            return false;
        }
        return true;
    }
};
