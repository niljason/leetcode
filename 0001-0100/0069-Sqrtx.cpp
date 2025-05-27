class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int ans = 1;
        int low = 1;
        int high = x;
        while (low <= high) {
            long mid = low + (high-low)/2;
            if (mid*mid <= x) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};

// approach 1 using math
int mySqrt(int x) {
    int ind = 1;
    while (x >= 0) {
        x -= (2 * ind) - 1;
        ind++;
    }
    return ind - 2;
}
