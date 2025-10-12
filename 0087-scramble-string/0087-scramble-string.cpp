class Solution {
    bool solve(string &s1, string &s2, int i1, int i2, int len, vector<vector<vector<int>>>& memo) {
        if (s1.compare(i1, len, s2, i2, len)==0) return true;
        if (len <= 1) return false;
        if (memo[i1][i2][len]!=-1) return memo[i1][i2][len];
        for (int k=1; k<len; k++) {
            if (solve(s1, s2, i1, i2, k, memo) && solve(s1, s2, k+i1, k+i2, len-k, memo)) return memo[i1][i2][len]=1;
            if (solve(s1, s2, i1, i2+len-k, k, memo) && solve(s1, s2, i1+k, i2, len-k, memo)) return memo[i1][i2][len]=1;
        } 
        return memo[i1][i2][len]=0;
    }
public:
    bool isScramble(string s1, string s2) {
        int n=s1.length();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
        return solve(s1, s2, 0, 0, n, memo);
    }
};