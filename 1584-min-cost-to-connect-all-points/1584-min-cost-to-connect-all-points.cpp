class Solution {
public:
    vector<int> size;
    vector<int> parent;

    int findPar(int n) {
        if (parent[n] == n) {
            return n;
        }

        return parent[n] = findPar(parent[n]);
    }

    bool unionSize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) {
            return false;
        }

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;

        {
            for (int i = 0; i < n; i++) {
                for (int l = i+1; l < n; l++) {
                    int cost = abs(points[i][0] - points[l][0])
                        + abs(points[i][1] - points[l][1]);

                    edges.emplace_back(cost, i, l);
                }
            }
        }

        sort(edges.begin(), edges.end());

        size.assign(n+1, 1);
        parent.resize(n+1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int minCost = 0;
        
        for (auto &[cs, u, v] : edges) {
            if (unionSize(u, v)) {
                minCost += cs;
            }
        }

        return minCost;
    }
};