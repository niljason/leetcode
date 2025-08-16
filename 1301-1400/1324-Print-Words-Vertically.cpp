class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> words(begin, end);

        int maxLength = 0;
        for (string &s : words) { maxLength = max(maxLength, int(s.size())); }

        vector<string> result;
        for (int i = 0; i < maxLength; i++) {
            string currWord = "";
            string currPhrase = "";
            for (int j = 0; j < words.size(); j++) {
                if (i+1 <= words[j].size()) {
                    currPhrase += words[j][i];
                    currWord += currPhrase;
                    currPhrase = "";
                }
                else { currPhrase += " "; }
            }
            result.push_back(currWord);
        }
        return result;
    }
};
