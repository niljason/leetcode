class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> commonArr(A.size(), 0);
        unordered_set<int> setA;
        unordered_set<int> setB;
        int curr = 0;
        for (int i = 0; i < A.size(); i++) {
            setA.insert(A[i]);
            setB.insert(B[i]);
            // if same increment curr
            if (A[i] == B[i]) {
                curr++;
            }
            else {
                // if A[i] is in setB
                if (setB.count(A[i])) {
                    curr++;
                }
                // if B[i] is in setA already
                if (setA.count(B[i])) {
                    curr++;
                }
            }
            commonArr[i] = curr;
        }
        return commonArr;
    }
};
