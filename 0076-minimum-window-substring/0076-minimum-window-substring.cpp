class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        for (char c: t) {
            tmap[c]++;
        }

        int start = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int n = s.length();
        int l = 0;
        for (int r = 0; r < n; r++) {
            smap[s[r]]++;

            if (tmap.count(s[r]) && tmap[s[r]] == smap[s[r]]) formed++;

            while (l <= r && formed == tmap.size()) {
                if (r-l+1 < minLen) {
                    minLen = r-l+1;
                    start = l;
                }

                char leftch = s[l];
                smap[leftch]--;
                if (tmap.count(s[l]) && smap[s[l]] < tmap[s[l]]) formed--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};