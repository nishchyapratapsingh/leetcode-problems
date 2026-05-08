class Solution {
    static const int N = 1000005;
    static inline int prime[N];
    static inline int used = 0;

    static inline bool init = []() {
        prime[0] = prime[1] = -1;

        for (int i = 2; i * i < N; i++) {
            if (prime[i] == 0) {
                for (int j = i * i; j < N; j += i) {
                    prime[j] = -1;
                }
            }
        }

        return true;
    }();

public:
    int minJumps(vector<int>& nums) {

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> pos(mx + 1);

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        used++;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (prime[val] != -1 && prime[val] != used) {

                prime[val] = used;

                for (int x = val; x <= mx; x += val) {

                    for (int idx : pos[x]) {

                        if (dist[idx] == -1) {
                            dist[idx] = dist[i] + 1;
                            q.push(idx);
                        }
                    }

                    pos[x].clear();
                }
            }
        }

        return -1;
    }
};