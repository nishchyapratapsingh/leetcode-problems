class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int len=0;
        while(i>=0 && s[i]==' ') {
            i--;
        }
        while (i>=0) {
            if (s[i]==' ') {
                return len;
            }
            len++;
            i--;
        }
        return len;
    }
};