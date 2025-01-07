class Solution {
public:
    int maximumSwap(int num) {

        vector<int> digits;
        while (num != 0) {
                digits.push_back(num % 10);
            num = num / 10;
        }

        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] == '9') continue; 
            int pos = 0;
            for (int j = 0; j < i; j++) {
                if (digits[j] > digits[pos]) {
                    pos = j;
                }
            }
            if (digits[pos] > digits[i]) {
                swap(digits[pos], digits[i]);
                break;
            }
        }

        int value = 0;
        for (int i = digits.size(); i > 0; i--) {
            value *= 10;
            value += digits[i-1];
        }
        return value;
    }
};
