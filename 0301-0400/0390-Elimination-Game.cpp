class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int add = 1;
        while (n > 1) {
            // left
            n /= 2;
            head += add;
            add *= 2;
            if (n <= 1) { return head; }
            // right
            bool odd = n % 2 == 1;
            n /= 2;
            if (odd) { head += add; }
            add *= 2;
        }
        return head;
    }
};
