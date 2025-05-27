class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) { return 1; }
        if (n == 1) { return x; }
        double half = myPow(x, abs(n/2));
        if (n > 0) {
            return half*half*myPow(x, abs(n%2));
        }
        else {
            return 1/(half*half*myPow(x, abs(n%2)));
        }
    }
};
