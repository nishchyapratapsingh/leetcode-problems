class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto &e : roads) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(1);
        int minPath = 1e9;
        vis[1] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                minPath = min(wt, minPath);

                if (vis[adjNode]) continue;

                q.push(adjNode);
                vis[adjNode] = 1;
            }
        }

        return minPath;
    }
};