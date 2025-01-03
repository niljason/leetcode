class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int copy = x;
        int reversed = 0;
        while (copy != 0) {
            if (INT_MAX/10 < reversed) { return false; }
            reversed *= 10;
            reversed += copy % 10;
            copy = copy / 10;
        }
        return reversed == x;
    }
};
