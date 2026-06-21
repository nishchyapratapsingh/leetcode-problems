class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto &edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
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

        vector<int> sorted;
        while (!q.empty()) {
            int nd = q.front();
            sorted.push_back(nd);
            q.pop();

            for (auto &it : adj[nd]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
            }
        }
        
        return sorted.size() == n;
    }
};