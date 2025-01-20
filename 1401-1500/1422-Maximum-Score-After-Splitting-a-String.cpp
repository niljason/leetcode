class Solution {
public:
    int maxScore(string s) {
        int rightOnes = 0;
        for (char c : s) {
            if (c == '1') { rightOnes++; }
        }

        int leftZeroes = 0;
        int score = 0;
        for (int i = 0; i < s.size()-1; i++) {
            char c = s[i];
            if (c == '1') { rightOnes--; }
            if (c == '0') { leftZeroes++; }
            score = max(score, leftZeroes + rightOnes);
        }
        return score;
    }
};
