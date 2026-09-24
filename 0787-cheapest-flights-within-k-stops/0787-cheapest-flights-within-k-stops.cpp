class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<tuple<int, int, int>> q;
        q.emplace(0, src, 0); //stops, node, dist

        while (!q.empty()) {
            auto[st, nd, ds] = q.front();
            q.pop();

            if (st > k) continue;

            for (auto &[neb, cost] : adj[nd]) {
                
                if (ds + cost < dist[neb]) {
                    dist[neb] = ds + cost;
                    q.emplace(st+1, neb, ds+cost);
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};