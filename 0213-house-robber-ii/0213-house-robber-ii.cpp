class Solution {
public:
    int robhelp(vector<int>& nums, int lo, int hi) {
        if (nums.size() == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int i=lo; i<=hi; ++i) {
            int tmp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = tmp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robhelp(nums, 0, nums.size()-2), robhelp(nums, 1, nums.size()-1));
    }
};