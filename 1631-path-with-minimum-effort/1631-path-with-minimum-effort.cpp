class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        using tp = tuple<int, int, int>;

        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.emplace(0, 0, 0);

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto[ds, r, c] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int edge = abs(heights[r][c] - heights[nr][nc]);
                    int neweffort = max(edge, ds);

                    if (neweffort < dist[nr][nc]) {
                        dist[nr][nc] = neweffort;
                        pq.emplace(neweffort, nr, nc);
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};