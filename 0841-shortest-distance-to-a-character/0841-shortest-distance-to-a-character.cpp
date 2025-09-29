class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
         int n = s.size();
        vector<int> res(n, n); \

        int prev = -n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            res[i] = i - prev;
        }

        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            res[i] = min(res[i], prev - i);
        }

        return res;
    }
};