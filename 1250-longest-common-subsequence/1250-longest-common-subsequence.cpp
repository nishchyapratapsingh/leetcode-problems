// class Solution {

//     int helper(string s1, string s2, int m, int n, vector<vector<int>> memo) {
//         if (n==0 || m==0) return 0;
//         if (memo[m][n]!=-1) {
//             return memo[m][n];
//         }

//         if (s1[m-1]==s2[n-1]) {
//             return 1+helper(s1, s2, m-1, n-1, memo);
//         }
//         else {
//             memo[m][n]= max(helper(s1, s2, m-1, n, memo),
//             helper(s1, s2, m, n-1, memo));
//         }
//         return memo[m][n];
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.length();
//         int n=text2.length();
//         vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
//         return helper(text1, text2, m, n, memo);
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for (int i=0; i<=n; i++) {
            dp[i][0] = 0;
        }
        for (int j=0; j<=m; j++) {
            dp[0][j] = 0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};