class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int count = 1;
        while (true) {
            if (temp - count <= 0) {
                return count - temp;
            }
            temp = temp - count;
            count *= 2;
        }
    }
};
