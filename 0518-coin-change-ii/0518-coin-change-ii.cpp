class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int n=coins.size();
        // if (amount==4681) return 0;
        // vector<vector<int>> dp(n+1, vector<int> (amount+1)); 
        // for (int i=0; i<=n; i++) {
        //     dp[i][0]=1;
        // }
        // for (int j=1; j<= amount; j++) {
        //     dp[0][j]=0;
        // }
        // for (int i=1; i<=n; i++) {
        //     for (int j=0; j<=amount; j++) {
        //         if (coins[i-1]>j) dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        //     }
        // }

        vector<int> dp(amount+1);
        dp[0]=1;
        for (int c: coins) {
            for (int j=c; j<=amount; j++) {
                dp[j] += dp[j-c];
            }
        }
        return dp[amount];
    }
};