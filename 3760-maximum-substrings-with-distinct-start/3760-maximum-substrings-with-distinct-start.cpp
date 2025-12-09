class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<int, int> freq;
        for (char c:s) {
            freq[c-'a']++;
        }
        int cnt = 0;
        for (int i=0; i<26; i++) {
            if (freq[i]>=1) cnt++;
        }
        return cnt;
    }
};