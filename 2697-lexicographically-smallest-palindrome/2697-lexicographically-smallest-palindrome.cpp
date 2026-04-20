class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        
        for (int i = 0; i < n / 2; i++) {
            char left = s[i];
            char right = s[n - 1 - i];
            
            if (left != right) {
                char smaller = min(left, right);
                s[i] = smaller;
                s[n - 1 - i] = smaller;
            }
        }
        
        return s;
    }
};