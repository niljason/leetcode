class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long mod = pow(10, 9) + 7;
        long long mid = target/2;
        long long result = 0;
        if ( n <= mid) {
            result = (n*1LL*(n+1)/2) % mod;
            return result;
        }
        result = mid*1LL*(mid + 1)/2 + ( n - mid )* 1LL* target +  ( n - mid)*1LL* ( n - mid - 1)/2;
        return result % mod;
    }
};
