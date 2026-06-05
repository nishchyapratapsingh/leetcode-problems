class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int sz = digits.size();
        int ans = 0;
        string t = to_string(n);
        int len = t.length();
        for (int i = 1; i < len; i++) {
            ans += pow(sz, i);
        }

        for (int i = 0; i < len; i++) {
            bool isSameDigit = false;

            for (string d: digits) {
                char ch = d[0];

                if (ch < t[i]) {
                    ans += pow(sz, len-i-1);
                }
                else if (ch == t[i]) {
                    isSameDigit = true;
                }
            }

            if (!isSameDigit) return ans;
        }

        return ans+1;
    }
};