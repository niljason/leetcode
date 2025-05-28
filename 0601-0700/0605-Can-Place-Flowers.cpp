class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if (flowerbed.size() == 1) {
            return (flowerbed[0] == 0 && n <= 1) || n == 0;
        }
        vector<int> flowers(flowerbed);
        for (int i = 0; i < flowers.size(); i++) {
            if (flowers[i] == 0) {
                // if 0th element and there exists a next element
                if (i == 0 && i < flowers.size()-1) {
                    if (flowers[i+1] == 0) { count++; flowers[i] = 1; }
                }
                // if last element
                else if (i == flowers.size()-1 && i > 0) {
                    if (flowers[i-1] == 0) { count++; flowers[i] = 1; }
                }
                // both left and right exist
                else if (flowers[i-1] == 0 && flowers[i+1] == 0) { count++; flowers[i] = 1; }
                // case for one element
            }
        }
        return n <= count;
    }
};
