class Solution {
public:
    char kthCharacter(int k) {
        int count = 0;
        k--;
        while ( k != 0) {
            if (k % 2 == 1) { count++; }
            k = k/2;
        }
        return 'a' + (count % 26);
    }
};
