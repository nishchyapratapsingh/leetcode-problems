class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> cipher;
        unordered_map<char, bool> used;
        for (int i=0; i<n; i++) {
            if (cipher.find(s[i])!=cipher.end()) {
                if (cipher[s[i]] != t[i]) {
                    return false;
                }
            }
            else if (cipher[s[i]] == t[i]) continue;
            else if (used[t[i]]) return false;
            else {
                cipher[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;
    }
};