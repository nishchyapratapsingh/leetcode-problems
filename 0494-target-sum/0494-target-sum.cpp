class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(), totalsum=0;
        for (int num: nums) totalsum+=num;
        if (totalsum<target) return 0;
        if ((totalsum+target)%2!=0) return 0;
        if (totalsum+target<0) return 0;
        target = (totalsum+target)/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        for (int i=0; i<=n; ++i) {
            dp[i][0] = 1;
        }
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=target; ++j) {
                if (nums[i-1]>j) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};