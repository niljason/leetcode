class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> results;
        char curr = s[0];
        int count = 0;
        for (char c : s) {
            if (c == curr) { count++; }
            else {
                // 1 -> pos and 0 -> neg
                if (curr == '0') { results.push_back(count*-1);}
                else { results.push_back(count);}
                curr = c;
                count = 1;
            }
        }
        if (curr == '0') { results.push_back(count*-1);}
        else { results.push_back(count);}

        int ind = -1; // store best ind
        int maxi = 0; // store best block
        // find best block of 010
        for (int i = 1; i < results.size()-1; i++) {
            // block of 1s
            if (results[i] > 0) {
                int count = abs(results[i-1]) + abs(results[i+1]);
                if (maxi < count) {
                    maxi = count;
                    ind = i;
                }
            }
        }
        if (ind != -1) {
            results[ind-1] = abs(results[ind-1]);
            results[ind+1] = abs(results[ind+1]);
        }
        int ans = 0;
        for (int i : results) {
            if (i > 0) {
                ans += i;
            }
        }
        return ans;
    }
};
