class Solution {
public:
    int distinctSubseqII(string s) {
        long long n = s.length();
        long long mod = 1e9 + 7;
        vector<long long> t(n+1);
        t[0] = 1;
        vector<int> last(26, -1);

        for (long long i = 1; i < n+1; i++) {
            t[i] = (t[i-1]*2)%mod;

            if (last[s[i-1] - 'a'] != -1) {
                t[i] = ((t[i] - t[last[s[i-1] - 'a']])%mod + mod)%mod;
            }
            
            last[s[i-1] - 'a'] = i-1;
        }

        return (t[n]-1+mod)%mod;
    }
};