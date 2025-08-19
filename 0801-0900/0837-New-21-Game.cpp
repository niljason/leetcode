class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1, 0);
        double prob = 1.0/double(maxPts);
        dp[0] = 1;
        double s = k > 0 ? 1 : 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = s * prob;
            if (i < k) { s += dp[i];}
            if (i - maxPts >= 0 && i-maxPts < k) {
                s -= dp[i-maxPts];
            }
        }
        double result = 0.0;
        for (int i = k; i <= n; i++) {
            result += dp[i];
        }
        return result;
    }
};
