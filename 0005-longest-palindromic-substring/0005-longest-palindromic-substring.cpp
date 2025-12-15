class Solution {
    int expandCenter(string &s, int left, int right) {
        int len = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        } 
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length(); 
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandCenter(s, i, i);
            int len2 = expandCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i-(len-1)/2;
            } 
        }
        return s.substr(start, maxLen);
    }
};