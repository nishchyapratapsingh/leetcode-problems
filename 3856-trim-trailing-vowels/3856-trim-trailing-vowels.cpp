class Solution {
    bool isVowel(char c) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        return st.count(c);
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