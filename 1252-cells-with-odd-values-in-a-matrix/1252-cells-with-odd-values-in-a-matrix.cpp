class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (auto &it : indices) {
            for (int i = 0; i < m; i++) {
                mat[it[0]][i] = !mat[it[0]][i];
            }
            for (int j = 0; j < n; j++) {
                mat[j][it[1]] = !mat[j][it[1]];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) cnt++;
            }
        }

        return cnt;
    }
};