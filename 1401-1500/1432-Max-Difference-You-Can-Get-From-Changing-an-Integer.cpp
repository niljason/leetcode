class Solution {
public:
    int maxDiff(int num) {
        int numCopy = num;
        int prev = numCopy % 10;
        bool sameDigit = true;
        vector<int> digits;
        while (numCopy > 0) {
            digits.push_back(numCopy % 10);
            sameDigit = sameDigit && (numCopy % 10 == prev);
            prev = numCopy % 10;
            numCopy /= 10;
        }

        // default replacement values to get min max
        int mini = 1;
        int maxi = 9;
        

        // what digit to choose for getting the max number
        int ind = digits.size()-1;
        int maxReplace = digits[ind];
        // find the first leading digit that is not 9
        while (maxReplace == 9 && ind > 0) {
            maxReplace = digits[--ind];
        }

        ind = digits.size()-1; // reset ind
        int minReplace = digits[ind];
        // find first non 1 digit to replace with 0
        while ((minReplace == 1 || minReplace == 0) && ind > 0) {
            minReplace = digits[--ind];
            mini = 0;
        }

        if (sameDigit) { mini = 1; }
        
        int minNum = 0;
        int maxNum = 0;
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] == minReplace) { minNum = minNum * 10 + mini; }
            else { minNum = minNum * 10 + digits[i]; }
            if (digits[i] == maxReplace) { maxNum = maxNum * 10 + maxi; }
            else { maxNum = maxNum * 10 + digits[i]; }
        }

        return maxNum - minNum;
    }
};
