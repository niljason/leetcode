bool comparator(const string& a, const string& b) {
    return a+b > b+a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        int zeroes = 0;

        vector<string> numStr;
        for (int num: nums) {
            if (num == 0) { zeroes++; }
            numStr.push_back(to_string(num));
        }
        if (zeroes == nums.size() && zeroes != 1) { return "0"; }
        sort(numStr.begin(), numStr.end(), comparator);
        string result = "";
        for (string& str : numStr) {
            result += str;
        }
        return result;
    }
};
