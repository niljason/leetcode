class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int ind = s.size()-i-1;
            if (s[ind] == '0') count++;
            else {
                if (sum + pow(2,i) <= k) {
                    sum += pow(2,i);
                    count++;
                }
            }
        }
        return count;
    }
};
