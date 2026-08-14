class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int l = 0;

        int mx = 0;

        vector<int> freq(26, 0);

        for (int r = 0; r < n; r++) {
            int c = s[r] - 'a';
            freq[c]++;

            while (l <= r && freq[c] > 2) {
                int left = s[l] - 'a';
                freq[left]--;
                l++;
            }

            mx = max(mx, r-l+1);
        }

        return mx;
    }
};