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
    const int N = 2e4+2;

    int removeStones(vector<vector<int>>& stones) {
        DSU ds(N);
        vector<bool> used(N);

        for (auto &it : stones) {
            int x = it[0], y = it[1];
            used[x] = 1;
            used[y+10001] = 1;
            ds.unionSize(x, y+10001);
        }

        int comp = 0;

        for (int i = 0; i < N; i++) {      
            if(used[i] && ds.findPar(i) == i) {
                comp++;
            }
        }

        return stones.size() - comp;
    }
};