class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int slow = 0;
        int fast = 1;
        while (fast != nums.size()) {
            if (nums[slow] == nums[fast] && fast - slow > 1) {
                nums.erase(nums.begin()+fast-1);
            } else if (nums[slow] == nums[fast]) {
                fast++;
            } else {
                slow++;
            }
        }
        return nums.size();
    }
};
