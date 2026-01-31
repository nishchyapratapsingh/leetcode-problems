class Solution {
    void solve(vector<vector<string>> &ans,
        vector<string> &sol,
        vector<bool> &col,
        vector<bool> &dia1,
        vector<bool> &dia2, int row, int n) {
        if (row == n) {
            ans.push_back(sol);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !dia1[row-c+n-1] && !dia2[row+c]) {
                vector<char> curr(n, '.');
                curr[c] = 'Q';
                col[c] = 1;
                dia1[row-c+n-1] = 1;
                dia2[row+c] = 1;
                sol.push_back(string(curr.begin(), curr.end()));

                solve(ans, sol, col, dia1, dia2, row+1, n);

                sol.pop_back();
                col[c] = 0;
                dia1[row-c+n-1] = 0;
                dia2[row+c] = 0;
            } 
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> sol;
        vector<bool> col(n);
        vector<bool> dia1(2*n-1);
        vector<bool> dia2(2*n-1);

        solve(ans, sol, col, dia1, dia2, 0, n);

        return ans;
    }
};