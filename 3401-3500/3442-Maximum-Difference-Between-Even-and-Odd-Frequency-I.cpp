class Solution {
public:
    int maxDifference(string s) {
        vector<int> alpha(26,0);
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i]-'a']++;
        }
        int mini = 100;
        int maxi = 0;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] % 2 == 0 && alpha[i] != 0) mini = min(mini, alpha[i]);
            if (alpha[i] % 2 == 1) maxi = max(maxi, alpha[i]);
        }
        return maxi-mini;
    }
};
