class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }
        string result = "";
        int jmp = 2*numRows - 2;
        for (int i = 0; i < numRows; i++) {
            int k = i;
            while (k < s.size()) {
                if (i != numRows-1) {
                    result += s[k];
                    k += (jmp - 2*i);
                }
                if (i != 0 && k < s.size()) {
                    result += s[k];
                    k += 2*i;
                }
            }
        }
        return result;
    }
};
