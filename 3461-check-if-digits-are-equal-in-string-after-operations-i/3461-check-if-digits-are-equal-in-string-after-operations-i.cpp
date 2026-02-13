class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.length() == 2 && s[0] == s[1]) {
            return true;
        } 

        if (s.length() == 2) {
            return false;
        }
        string temp;
        for (int i = 1; i < s.length(); i++) {
            temp.push_back((s[i-1]+s[i]) % 10);
        }

        return hasSameDigits(temp);
    }
};