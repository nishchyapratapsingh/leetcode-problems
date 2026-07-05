class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};

        queue<tuple<int, int, int>> q;

        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();

            if (r == n-1 && c == n-1) {
                return d;
            }

            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 0) {
                    q.push({nr, nc, d+1});
                    grid[nr][nc] = 1;
                }
            }
        }

        return -1;
    }
};