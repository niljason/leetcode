class Solution {
public:
    int fib(int n) {
        int b = 0;
        int a = 1;
        int sum = 0;
        if (n == 0) { return b; }
        if (n == 1) { return a; }
        for (int i = 2; i <= n; i++) {
            sum = a + b;
            b = a;
            a = sum;
        }
        return a;
    }
};
