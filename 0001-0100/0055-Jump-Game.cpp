class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxy = nums[0];
        for (int i = 0; i < nums.size(); i++) {
        // if we ever jump over it or at it then we can reach it
            if (maxy >= nums.size()-1) { return true; }
        // if the curr jump is 0 and that's the max we can reach to then we can never reach the end
            if (nums[i] == 0 && maxy == i) { return false; }
            maxy = max(maxy, i + nums[i]);
        } 
        return false;
    }
};

/* Alternatively dp tabulation soln
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) { return true; }
        vector<bool> table(nums.size(), false);

        return update(nums, table, 0);
    }

    bool update(vector<int>& nums, vector<bool>& table, int pos) {
        if (pos == table.size()-1) { return true; }
        if (table[pos]) { return false; }
        table[pos] = true;
        for (int i = 1; i <= nums[pos]; i++) {
            if (update(nums, table, pos+i)) { return true; }
        }
        return false;
    }
};
*/


