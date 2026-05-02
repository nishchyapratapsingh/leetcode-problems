class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<bool>> vis(n, vector<bool> (m, 0));

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;

                cnt++;
                
                queue<pair<int, int>> q;
                q.emplace(i, j);
                // vis[i][j] = 1;
                grid[i][j] = '0';

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    int nr, nc;

                    for (int i = 0; i < 4; i++) {
                        nr = r + dr[i];
                        nc = c + dc[i];

                        if (nr >= 0 && nr < n && nc >= 0 
                        && nc < m 
                        // && !vis[nr][nc]
                        && grid[nr][nc] == '1') {
                            q.emplace(nr, nc);
                            // vis[nr][nc] = 1;
                            grid[nr][nc] = '0';
                        }
                    }
                }
            }
        }

        return cnt;
    }
};