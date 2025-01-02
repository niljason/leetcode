class Solution {
public:
    int reverse(int x) {
        int val = 0;
        while (x != 0) {
            if (val > INT_MAX/10) return 0;
            if (INT_MIN/10 > val) return 0;
            val*=10;
            val += (x%10);
            x = x/10;
        }
        return val;
    }
};
