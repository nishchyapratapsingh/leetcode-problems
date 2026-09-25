class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); //{to, cost}

        for (auto &it : times) {
            adj[it[0]].emplace_back(it[1], it[2]);
        }

        vector<int> delay(n+1, INT_MAX);
        delay[k] = 0;

        using pr = pair<int, int>;
        priority_queue<pr, vector<pr>, greater<pr>> pq; //{delay, node}

        pq.emplace(0, k);

        while (!pq.empty()) {
            auto[dl, nd] = pq.top();
            pq.pop();

            if (dl > delay[nd]) {
                continue;
            }

            for (auto &[nb, tm] : adj[nd]) {
                if (dl + tm < delay[nb]) {
                    delay[nb] = dl + tm;
                    pq.emplace(delay[nb], nb);
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int d = delay[i];
            if (d == INT_MAX) {
                return -1;
            }

            ans = max(d, ans);
        }

        return ans;
    }
};