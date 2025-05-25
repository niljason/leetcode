class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) { return "1"; }
        else {
            string result = countAndSay(n-1);
            return RLE(result);
        }
    }

    string RLE(string& str) {
        string result = "";
        int count = 0;
        char num = str[0];
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == num) { count++; }
            else {
                result += to_string(count);
                result.append(1, num);
                count = 1;
                num = str[i];
            }
        }
        result += to_string(count);
        result.append(1, num);
        return result;
    }
};
