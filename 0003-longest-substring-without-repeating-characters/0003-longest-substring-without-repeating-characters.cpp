class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        int n = s.length();
        int l=0;
        int longest = 0;

        if (n==0) return 0;

        for (int r=0; r<n; r++) {
            freq[(int)s[r]]++;

            while (freq[(int)s[r]] > 1) {
                freq[(int)s[l]]--;
                l++;
            } 

            longest = max(longest, r-l+1);

        }

        return longest;
    }
};