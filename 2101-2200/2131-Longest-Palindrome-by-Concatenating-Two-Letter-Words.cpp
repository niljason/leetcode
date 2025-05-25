class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> pairs;
        int length = 0;
        for (int i = 0; i < words.size(); i++) {
            pairs[words[i]]++;
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            // same letters
            if (words[i] == rev) {
                if (pairs[words[i]] >= 2) {
                    pairs[words[i]] -= 2;
                    length += 4;
                }
            }
            else {
                if (pairs[rev] >= 1) {
                    pairs[rev] -= 1;
                    pairs[words[i]] -= 1;
                    length += 4;
                }
            }
        }

        for (auto pair: pairs) {
            string curr = pair.first;
            string rev = curr;
            reverse(rev.begin(), rev.end());
            if (curr == rev && pairs[curr] == 1) {
                length += 2;
                break;
            }
        }
        return length;
    }
};
