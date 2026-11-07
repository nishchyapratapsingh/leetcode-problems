class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u';
    }
public:
    string trimTrailingVowels(string s) {
        int n = s.length();

        for (int i = n-1; i >= 0; i--) {
            if (!isVowel(s[i])) {
                return s.substr(0, i+1);
            }
        }

        return "";
    }
};