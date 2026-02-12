class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int ones = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
        }

        for (int i = 0; i < ones-1; i++) {
            s[i] = '1';
        }

        for (int i = ones-1; i < n; i++) {
            s[i] = '0';
        }

        s[n-1] = '1';

        return s;

    }
};