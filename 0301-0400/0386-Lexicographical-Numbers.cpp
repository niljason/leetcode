class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curr = 1;
        vector<int> results;
        results.push_back(curr);
        while (results.size() != n) {
            if (curr * 10 <= n) {
                curr *= 10;
                results.push_back(curr);
            }
            else if (curr % 10 == 9) {
                curr = curr/10 + 1;
                while (curr % 10 == 0) { curr = curr/10; }
                results.push_back(curr);
            }
            else if (curr+1 <= n) {
                curr++;
                results.push_back(curr);
            }
            else {
                curr = curr/10 + 1;
                while (curr % 10 == 0) { curr = curr/10; }
                results.push_back(curr);
            }
        }
        return results;
    }
};
