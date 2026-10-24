class Solution {
public:
    vector<int> size;
    vector<int> parent;
    
    int findPar(int n) {
        if (n == parent[n]) {
            return n;
        }   
        
        return parent[n] = findPar(parent[n]);
    }
    
    void unionSize(int u, int v) {
        int pu = findPar(u), pv = findPar(v);
        
        if (pu == pv) return;
        
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        size.assign(V, 1);
        parent.resize(V);
        
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < V; i++) {
            for (int k = i+1; k < V; k++) {
                if (isConnected[i][k]) {
                    unionSize(i, k);
                }
            }
        }
        
        unordered_set<int> s;
        for (int i = 0; i < V; i++) {
            s.insert(findPar(i));
        }
        
        return s.size();
    }
};