class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.length();
        vector<int> freq(26, 0);
        int maxfreq=0;
        int maxLen = 0;

        for (int r=0; r<n; r++) {
            freq[s[r]-'A']++;
            maxfreq = max(freq[s[r]-'A'], maxfreq);

            if (r-l+1 - maxfreq > k) {
                freq[s[l]-'A']--;
                l++;   
            }
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};