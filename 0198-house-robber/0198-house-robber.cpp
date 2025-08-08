class Solution {
private:
    int robHelper(vector<int>& nums, vector<int>& memo, int i) {
        if (i<0) {
            return 0;
        }
        if (memo[i]>=0) {
            return memo[i];
        }
        int res = max(robHelper(nums, memo, i-2)+nums[i], robHelper(nums, memo, i-1));
        memo[i] = res;
        return res;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1, -1);
        return robHelper(nums, memo, n-1);
    }
};