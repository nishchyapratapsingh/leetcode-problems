class Solution {
public:
    int numSquares(int n) {
        vector<int> sqrs;
        for (int i=1; i*i<=n; i++) {
            sqrs.push_back(i*i);
        }
        vector<int> dp(n+1, INT_MAX-1);
        dp[0]=0;
        for (int j=1; j<=n; j++) {
            for (int sq: sqrs) {
                if (sq>j) break;
                dp[j] = min(dp[j], dp[j-sq]+1); 
            }
        }
        return dp[n]==INT_MAX-1?n:dp[n];
    }
};