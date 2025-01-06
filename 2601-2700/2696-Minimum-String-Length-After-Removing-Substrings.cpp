class Solution {
public:
    int minLength(string s) {
        stack<char> arr;
        for (int i = 0; i < s.size(); i++) {
            if (arr.size() != 0 && arr.top() == 'A' && s[i] == 'B') {
                arr.pop();
            }
            else if (arr.size() != 0 && arr.top() == 'C' && s[i] == 'D') {
                arr.pop();
            }
            else {
                arr.push(s[i]);
            }
        }
        return arr.size();
    }
};
