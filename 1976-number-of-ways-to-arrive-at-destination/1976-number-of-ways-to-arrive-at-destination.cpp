class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &rd : roads) {
            adj[rd[0]].emplace_back(rd[1], rd[2]);
            adj[rd[1]].emplace_back(rd[0], rd[2]);
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;

        using pr = pair<long long, long long>;
        const int MOD = 1e9+7;

        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto[ds, nd] = pq.top();
            pq.pop();

            for (auto &[nb, cs] : adj[nd]) {
                if (ds + cs < dist[nb]) {
                    dist[nb] = ds + cs;
                    pq.emplace(dist[nb], nb);
                    ways[nb] = ways[nd];
                }
                else if (ds + cs == dist[nb]) {
                    ways[nb] = (ways[nd] + ways[nb]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};