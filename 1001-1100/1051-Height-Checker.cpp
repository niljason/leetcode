class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cp(heights);
        sort(cp.begin(), cp.end());
        int x = 0;
        for (int ind = 0; ind < heights.size(); ++ind) {
            if (heights[ind] != cp[ind]) {
                x++;
            }
        }
        return x;

    }
};
