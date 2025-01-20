class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string currWord = "";
        for (char c : s) {
            if (c == ' ' && currWord.size() > 0) {
                if(result.size() != 0) { result = currWord + " " + result; }
                else { result += currWord; }
                currWord = "";
            } else if (c != ' ') {
                currWord += c;
            }
        }
        if (currWord.size() > 0) {
            if (result.size() > 0) { result = currWord + " " + result; }
            else { result = currWord; }
        }
        return result;
    }
};
