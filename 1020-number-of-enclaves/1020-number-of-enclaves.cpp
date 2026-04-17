class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int ones = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ones++;
                }
                if (grid[i][j] == 1 && (i == 0 || j == 0 || i == n-1 || j == m-1)) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                    ones--;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            auto[r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1) {
                    q.emplace(nr, nc);
                    grid[nr][nc] = 0;
                    ones--;
                }
            }
        }

        return ones;
    }
};