class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
            }
        );

        vector<int> diff(nums.size()+1, 0);
        priority_queue<int> heap;
        int sum = 0;
        int ind = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += diff[i];
            while (ind < queries.size() && queries[ind][0] == i) {
                heap.push(queries[ind][1]);
                ind++;
            }
            while (sum < nums[i] && !heap.empty() && heap.top() >= i) {
                sum++;
                diff[heap.top() + 1]--;
                heap.pop();
            }
            if (sum < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};
