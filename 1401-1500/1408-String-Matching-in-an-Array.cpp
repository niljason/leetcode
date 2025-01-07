class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> substrings;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (isSub(words[i], words[j])) {
                    substrings.insert(words[j]);
                }
            }
        }

        vector<string> result(substrings.begin(), substrings.end());
        return result;
    }

    bool isSub(string& word, string& part) {
        if (word == part || part.size() > word.size()) {
            return false;
        }

        for (int i = 0; i < word.size(); i++) {
            int word_pos = i;
            int part_pos = 0;
            while (word[word_pos] == part[part_pos]) {
                word_pos++;
                part_pos++;
                if (part_pos == part.size()) { return true; }
            }
        }
        return false;
    }
};
