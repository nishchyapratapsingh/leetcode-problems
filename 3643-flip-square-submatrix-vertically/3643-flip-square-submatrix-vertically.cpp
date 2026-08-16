class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = y; i < y+k; i++) {
            int u = x;
            int v = x+k-1;

            while (u < v) {
                swap(grid[u++][i], grid[v--][i]);
            }
        }

        return grid;
    }
};