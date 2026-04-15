class Solution {
private:
    void bfs(int src, vector<vector<int>> &adj, vector<bool> &visited) {
        // code here        
        queue<int> q;
        q.push(src);
        
        visited[src] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto &it: adj[node]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<bool> visited(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                bfs(i, adj, visited);
            }
        }

        return cnt;
    }
};