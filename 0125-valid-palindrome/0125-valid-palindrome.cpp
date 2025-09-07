class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        if (n<=1) return true;
        int l=0;
        int r=n-1;
        while (l<=r) {
            if (l <= r && !isalpha(s[l]) && !isdigit(s[l])) {
            l++;
        }
        else if (l <= r && !isalpha(s[r]) && !isdigit(s[r])) {
            r--;
        }

        else if (tolower(s[l])!=tolower(s[r])) {
            return false;
        }
        else {
            l++;
            r--;
        }
        }
        return true;
    }
};