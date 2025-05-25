class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> results;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].contains(x)) {
                results.push_back(i);
            }
        }
        return results;
    }
};
