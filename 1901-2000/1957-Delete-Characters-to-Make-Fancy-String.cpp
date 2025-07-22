class Solution {
public:
    string makeFancyString(string s) {
        char curr = s[0];
        int count = 0;
        string res = "";
        for (char c : s) {
            if (c == curr) {
                count++;
            }
            else { count = 1; }
            curr = c;
            if (count < 3) {
                res.push_back(c);
            }
        }
        return res;
    }
};
