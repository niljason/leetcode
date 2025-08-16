class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal = arr[arr.size()-1];
        for (int i = arr.size()-1; i >= 0; i--) {
            int curr = arr[i];
            arr[i] = maxVal;
            maxVal = max(maxVal, curr);
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
