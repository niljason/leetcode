class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string curr_num = "";
        string curr_str = "";
        for (int i = 0; i < s.size(); i++) {
            // is a number
            if (isdigit(s[i])) {
                curr_num += s[i];
            }
            else if (curr_num != "!") {
                st.push(curr_num);
                curr_num = "";
            }

            if (isalpha(s[i])) {
                curr_str += s[i];
            }
            else if (curr_str != "") {
                st.push(curr_str);
                curr_str = "";
            }

            if (s[i] == ']') {
                string temp = "";
                while (st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // remove the [
                int times = stoi(st.top());
                st.pop(); // remove the digit;
                st.push(multiString(temp, times));
            }
            else if (s[i] == '[') {
                st.push("[");
            }
        }
        while (!st.empty()) {
            curr_str = st.top() + curr_str;
            st.pop();
        }
        return curr_str;
    }

    string multiString(string& str, int num) {
        string result = "";
        for (int i = 0; i < num; i++) {
            result += str;
        }
        return result;
    }
};
