class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto &edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> indegree(n);
        for (auto &it: adj) {
            for (auto nd : it) {
            indegree[nd]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
            q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int nd = q.front();
            cnt++;
            q.pop();

            for (auto &it : adj[nd]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
            }
        }
        
        return cnt == n;
    }
};