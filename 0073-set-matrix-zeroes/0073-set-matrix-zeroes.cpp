class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool> rowsToZero(n, false);
        vector<bool> columnsToZero(n, false);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == 0) {
                    rowsToZero[i] = true;
                    columnsToZero[j] = true;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (rowsToZero[i] || columnsToZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};