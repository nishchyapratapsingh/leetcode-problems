class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> freq(26);
        for(char c:s) {
            freq[c-'a']++;
        }
        for (char c:t) {
            freq[c-'a']--;
        }
        for (int i=0; i<26; i++) {
            if (freq[i]>=1) return false;
        }
        return true;
    }
};