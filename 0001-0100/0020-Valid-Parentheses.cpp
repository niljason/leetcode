class Solution {
public:
    bool isValid(string s) {
        stack<char> lst;
        if (s.size() % 2 == 1) { return false; }
        for (int ind = 0; ind < s.size(); ++ind) {
            char c = s[ind];
            if (c=='(' || c=='[' || c=='{') {
                lst.push(c);
            } else {
                if (lst.empty()) { return false; }
                else if (c == ')' && lst.top() == '(') {
                    lst.pop();
                }
                else if (c == ']' && lst.top() == '[') {
                    lst.pop();
                }
                else if (c == '}' && lst.top() == '{') {
                    lst.pop();
                }
                else {
                    return false;
                }
            }
        }
        return lst.empty();
    }
};
