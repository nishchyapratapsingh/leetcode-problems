class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<pair<int, int>> st;
        vector<int> dist(n+1, 1e9);

        dist[k] = 0;
        // pq.emplace(0, k);
        st.insert({0, k});

        while (!st.empty()) {
            // auto[dis, node] = pq.top();
            auto[dis, node] = *st.begin();
            // pq.pop();
            st.erase(st.begin());

            if (dis > dist[node]) {
                continue;
            }

            for (auto &it : adj[node]) {
                int wt = it.second;
                int adjNode = it.first;

                if (dis + wt < dist[adjNode]) {
                    //set optimisation
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + wt;
                    // pq.emplace(dis+wt, adjNode);
                    st.insert({dis+wt, adjNode});
                }
            }
        }

        int minDist = -1;
        
        for (int i = 1; i <= n; i++) {
            int d = dist[i];
            if (d == 1e9) {
                return -1;
            }

            minDist = max(minDist, d);
        }

        return minDist;
    }
};