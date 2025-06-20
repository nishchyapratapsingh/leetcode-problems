class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int count = 0;

        while (i<n && j<m) {
            while (j<m-1 && s[j]<g[i]) {
                j++;
            }
            if (s[j]>=g[i]) {
                count++;
                i++;
            }
            
            j++;
        }

        return count;
    }
};