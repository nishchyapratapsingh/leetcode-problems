class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        for (int i = n-1; i>=0; i--) {
            for (int j = 1; j <= k; j++) {
                curr[1][j] = max(-prices[i] + next[0][j], next[1][j]);
                curr[0][j] = max(prices[i]+next[1][j-1], next[0][j]);
            }
            next = curr;
        }
        return curr[1][k];
    }
};