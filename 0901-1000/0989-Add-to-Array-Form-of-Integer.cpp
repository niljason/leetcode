class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for (int ind = num.size(); ind > 0; --ind) {
            num[ind-1] = num[ind-1] + k % 10 + carry;
            carry = num[ind-1] / 10;
            num[ind-1] %= 10;
            k /= 10;
        }
        while (carry > 0 || k != 0) {
            int n = k % 10 + carry;
            carry = n / 10;
            k /= 10;
            num.insert(num.begin(), n % 10);
        }
        return num;
    }
};
