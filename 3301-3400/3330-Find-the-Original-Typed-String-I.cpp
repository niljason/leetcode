class Solution {
public:
    int possibleStringCount(string word) {
        int ways = 1;
        char c = word[0];
        int count = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == c) { count++; }
            else {
                ways += count - 1;
                count = 1;
                c = word[i];
            }
        }
        ways += count - 1;
        return ways;
    }
};
