class Solution {
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u';
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n/2; i++) {
            if (isVowel(s[i])) cnt1++;
            if (isVowel(s[n-i-1])) cnt2++;
        }

        return cnt1 == cnt2;
    }
};