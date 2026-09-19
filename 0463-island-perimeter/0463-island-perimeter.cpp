class Solution {
    int boundary(vector<vector<int>>& grid, int i, int j) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 0) {
                cnt++;
            }
        }

        return cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cnt = boundary(grid, i, j);
                    if (cnt == 4) {
                        peri += 4;
                    }
                    else if (cnt == 3) {
                        peri += 3;
                    }
                    else if (cnt == 2) {
                        peri += 2;
                    }
                    else if (cnt == 1) {
                        peri += 1;
                    }
                }
            }
        }

        return peri;
    }
};