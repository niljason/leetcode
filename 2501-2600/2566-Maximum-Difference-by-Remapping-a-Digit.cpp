class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> numDigit;
        int numCopy = num;
        // 0th index is the last digit
        while (numCopy != 0) {
            numDigit.push_back(numCopy % 10);
            numCopy /= 10;
        }
        int minReplacement = numDigit[numDigit.size()-1];
        int maxReplacement = numDigit[numDigit.size()-1];
        int ind = numDigit.size()-1;
        while (maxReplacement == 9) {
            if (ind == 0) { return num; }
            ind--;
            maxReplacement = numDigit[ind];
        }

        int mini = 0;
        int maxi = 0;
        for (int i = numDigit.size()-1; i >= 0; i--) {
            if (numDigit[i] == minReplacement) { mini = mini*10 + 0; }
            else {mini = mini*10 + numDigit[i]; }
            if (numDigit[i] == maxReplacement) { maxi = maxi*10 + 9; }
            else { maxi = maxi*10 + numDigit[i]; }
        }
        return maxi - mini;
    }
};
