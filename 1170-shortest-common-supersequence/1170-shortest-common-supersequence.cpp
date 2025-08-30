class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m=a.length(), n=b.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i=m, j=n;
        string res;
        while (i>0 && j>0) {
            if (a[i-1]==b[j-1]) {
                res.push_back(a[i-1]);
                i--;
                j--;
            }
            else if (dp[i][j-1]>dp[i-1][j]) {
                res.push_back(b[j-1]);
                j--;
            }
            else {
                res.push_back(a[i-1]);
                i--;
            }
        }
        while (i>0) {
            res.push_back(a[i-1]);
            i--;
        }
        while (j>0) {
            res.push_back(b[j-1]);
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
