class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        set<string> operations = {"+", "-", "*", "/"};
        for (int i = 0; i < tokens.size(); i++) {
            if (operations.find(tokens[i]) != operations.end()) {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if (tokens[i] == "+") { st.push(num1 + num2); }
                if (tokens[i] == "*") { st.push(num1 * num2); }
                if (tokens[i] == "-") { st.push(num2 - num1); }
                if (tokens[i] == "/") { st.push(num2 / num1); }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
