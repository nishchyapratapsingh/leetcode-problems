class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &check) {
        vis[node] = true;
        pathVis[node] = true;
        
        for (auto &it: adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<bool> pathVis(n, 0);
        vector<bool> check(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (check[i]) ans.push_back(i);
        }
        
        return ans;
    }
};