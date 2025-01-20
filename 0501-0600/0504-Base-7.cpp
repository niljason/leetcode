class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        bool neg = false;
        if (num < 0) { 
            num *= -1; 
            neg = true;
        }
        
        while (num >= 7) {
            result = static_cast<char>('0' + num % 7) + result;
            num /= 7;
        }
        result = static_cast<char>('0' + num % 7) + result;
        if (neg) { result = '-' + result; }
        return result;
    }
};
