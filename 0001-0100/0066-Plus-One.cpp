class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int ind = digits.size()-1;
        while (carry != 0 && ind >= 0) {
            digits[ind] = digits[ind]+carry;
            carry = digits[ind] / 10;
            digits[ind] = digits[ind] % 10;
            --ind;
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
