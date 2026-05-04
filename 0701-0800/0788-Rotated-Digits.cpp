class Solution {
public:
    int rotatedDigits(int n) {
        int counter = 0;
        int mp[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        for (int i = 0; i <= n; i++) {
            string x = to_string(i);
            string y = to_string(i);
            bool possible = true;
            for (char& c : y) {
                if (mp[c-'0'] < 0) {
                    possible = false;
                    break;
                }
                c = mp[c-'0'] + '0';
            }
            if (possible && x != y) { counter++; }
        }
        return counter;
    }
};
