class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxy = 0;
        int left = 0;
        int right = height.size()-1;
        while (left != right) {
            int val = (right-left) * min(height[left], height[right]);
            maxy = max(maxy, val);
            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return maxy;
    }
};
