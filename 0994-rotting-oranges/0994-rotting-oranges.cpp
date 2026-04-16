class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j, 0);
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int ans = 0;

        while (!q.empty()) {
            auto[row, col, time] = q.front();
            q.pop();
            ans = max(ans, time);

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr < n && nr >= 0 
                && nc < m && nc >= 0 
                && grid[nr][nc] == 1) {
                    q.emplace(nr, nc, time+1);
                    grid[nr][nc] = 2;
                    fresh--;
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};