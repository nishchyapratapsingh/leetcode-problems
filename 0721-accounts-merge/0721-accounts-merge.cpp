class DSU {
public:
    vector<int> size;
    vector<int> parent;

    DSU(int n) {
        size.assign(n+1, 0);
        parent.resize(n+1);

        for (int i = 0; i < n; i++) {
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
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
        else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();

            for (int j = 1; j < m; j++) {
                if (mp.count(accounts[i][j])) {
                    ds.unionSize(i, mp[accounts[i][j]]);
                }
                else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> merged;

        for (auto &[email, idx] : mp) {
            int root = ds.findPar(idx);
            merged[root].push_back(email);
        }

        vector<vector<string>> ans;
        
        for (auto &[x, y] : merged) {
            sort(y.begin(), y.end());

            vector<string> temp;
            temp.push_back(accounts[x][0]); 

            for (auto &email : y) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};