class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<long long>> dp(n+1, vector<long long>(amount+1, INT_MAX));
        // dp[0][0] = 0;

        // for (int i=1; i<=n; i++) {
        //     for (int j=0; j<=amount; j++) {
        //         if (coins[i-1]>j) dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
        //     }
        // }
        // return dp[n][amount]==INT_MAX?-1:dp[n][amount];
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for (int coin: coins) {
            for (int j=coin; j<=amount; j++) {
                dp[j] = min(dp[j], dp[j-coin]+1);
            }
        }
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};