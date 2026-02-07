class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(s.length() != words.size()) return false;

        int i = 0;
        for (string word: words) {
            if (s[i++] != word[0]) {
                return false;
            }
        }

        return true;
    }
};