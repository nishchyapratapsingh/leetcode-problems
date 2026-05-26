class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_set<char> special;
        unordered_set<char> lower;
        unordered_set<char> upper;

        for (char c: word) {
            if (c >= 'a' && c <= 'z') {
                lower.insert(c);
            }
            else if (c >= 'A' && c <= 'Z') {
                upper.insert(c);
            }

            if (lower.count(tolower(c)) && upper.count(toupper(c))) {
                special.insert(tolower(c));
            }
        }

        return special.size();
    }
};