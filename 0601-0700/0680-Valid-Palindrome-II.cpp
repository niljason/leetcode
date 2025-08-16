class Solution {
public:
    bool checkPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) { return false; }
            l++; r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++; right--;
            }
            else {
                return checkPalindrome(s, left+1, right) || checkPalindrome(s, left, right-1);
            }
        }
        return true;
    }
};
