class Solution {
public:
    int countKeyChanges(string s) {
        int cnt = 0;
        char curr = s[0];
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != curr && s[i] != toupper(curr)) {
                cnt++;
            }
            curr = tolower(s[i]);
        }

        return cnt;
    }
};