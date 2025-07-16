class Solution {
public:
    bool isValid(string word) {
        bool length = word.size() >= 3;
        bool vowel = false;
        bool consonant = false;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char c: word) {
            if (!isalnum(c)) { return false; }
            else if (find(vowels.begin(), vowels.end(), c) != vowels.end()) { vowel = true; }
            else if (c - '0' > 9) { consonant = true; }
        }
        return length && vowel && consonant;
    }
};
