class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> special;
        unordered_set<char> lower;
        unordered_set<char> upper;
        unordered_set<char> invalid;

        for (char c: word) {
            if (c >= 'a' && c <= 'z' && upper.count(toupper(c))) {
                invalid.insert(c);
                special.erase(c);
                continue;
            }
            else if (c >= 'a' && c <= 'z') {
                lower.insert(c);
            }
            else if (c >= 'A' && c <= 'Z') {
                upper.insert(c);
            }

            if (!invalid.count(tolower(c)) && lower.count(tolower(c)) && upper.count(toupper(c))) {
                special.insert(tolower(c));
            }
        }

        return special.size();
    }
};