class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while (i<n) {
            if (s[i] != ' ') break;
            i++;
        }
        int res = 0;
        bool pos = true;
        if (s[i] == '-') {
            pos = false;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        while (i<n) {
            if (s[i] != '0') break;
            i++;
        }
        while (i<n && s[i]-'0'>=0 && s[i]-'0'<=9) {
            if (res > 214748364 || s[i]-'0' > INT_MAX - res*10) return pos?INT_MAX:INT_MIN;
            res = res*10 + (s[i++]-'0');
        }
        return pos?res:0-res;
    }
};