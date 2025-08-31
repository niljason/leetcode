class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0;
        int maxArea = 0;
        for (auto& arr : dimensions) {
            double diag = (arr[0] * arr[0]) + (arr[1] * arr[1]);
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = arr[0] * arr[1];
            }
            if (diag == maxDiag) {
                maxArea = max(maxArea, arr[0] * arr[1]);
            }
        }
        return maxArea;
    }
};
