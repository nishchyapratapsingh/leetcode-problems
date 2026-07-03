class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);

        dist[k] = 0;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto[dis, node] = pq.top();
            pq.pop();

            for (auto &it : adj[node]) {
                int wt = it.second;
                int adjNode = it.first;

                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.emplace(dis+wt, adjNode);
                }
            }
        }

        int minDist = -1;
        dist[0] = -1; //it has never changed from infinity
        
        for (int &d : dist) {
            if (d == 1e9) {
                return -1;
            }

            minDist = max(minDist, d);
        }

        return minDist;
    }
};