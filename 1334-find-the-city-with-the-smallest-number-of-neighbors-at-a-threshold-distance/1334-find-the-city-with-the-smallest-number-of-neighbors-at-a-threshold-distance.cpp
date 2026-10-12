class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e8;
        vector<vector<int>> adm(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            adm[i][i] = 0;
        }

        for (auto &e : edges) {
            adm[e[0]][e[1]] = e[2];
            adm[e[1]][e[0]] = e[2];
        }


        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int l = 0; l < n; l++) {
                    adm[i][l] = min(
                        adm[i][k] + adm[k][l], adm[i][l]
                    );
                }
            }
        }

        int ans = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int l = 0; l < n; l++) {
                if (adm[i][l] <= distanceThreshold) {
                    cnt++;
                }
            }

            mn = min(cnt, mn);
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int l = 0; l < n; l++) {
                if (adm[i][l] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt == mn) ans = max(ans, i);
        }

        return ans;
    }
};