class Solution {
private:
    void f(int row, int n, int m, vector<vector<char>>& boxGrid, vector<vector<char>>& ans) {
        int i = n-1;
        int j = i;
        while (i >= 0) {
            if (boxGrid[row][i] == '#' && j >= 0) {
                ans[j][m-1-row] = '#';
                j--;
            }
            else if (boxGrid[row][i] == '*') {
                ans[i][m-1-row] = '*';
                if (i-1 >= 0) j = i-1;
            }
            i--;
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> ans(m, vector<char> (n, '.'));

        for (int i = 0; i < n; i++) {
            f(i, m, n, boxGrid, ans);
        }

        return ans;
    }
};