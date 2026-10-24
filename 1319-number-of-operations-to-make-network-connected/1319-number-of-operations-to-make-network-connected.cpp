class DSU {
  public: 
    vector<int> size;
    vector<int> parent;
    
    DSU(int n) {
        size.assign(n+1, 1);
        parent.resize(n+1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar(int n) {
        if (parent[n] == n) {
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
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        
        for (auto &e : connections) {
            ds.unionSize(e[0], e[1]);
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                cnt++;
            }
        }
        
        int m = connections.size();
        
        if (m - (n - cnt) >= cnt-1) {
            return cnt-1;
        } 
        
        return -1;
    }
};