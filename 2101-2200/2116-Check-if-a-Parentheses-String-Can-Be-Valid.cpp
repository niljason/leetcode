class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) { return false; }
        stack<int> wildcards;
        stack<int> openIndices;
        for (int i = 0; i < s.size(); i++) {
            // wildcards first as they can be changed
            if (locked[i] == '0') {
                wildcards.push(i);
            }
            else if (s[i] == '(') {
                openIndices.push(i);
            }
            else if (s[i] == ')') {
                if (!openIndices.empty()) { openIndices.pop(); }
                else if (!wildcards.empty()) { wildcards.pop(); }
                else { return false; }
            }
        }

        // match the rest of the '(' with a wildcard after it
        while (!openIndices.empty() && !wildcards.empty() && openIndices.top() < wildcards.top()) {
            openIndices.pop();
            wildcards.pop();
        }

        // once match all the '(' check that we have an even number of wildcards left
        if (openIndices.empty() && !wildcards.empty()) {
            return wildcards.size() % 2 == 0;
        }
        return openIndices.empty();
    }
};
