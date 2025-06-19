class Solution {
public:
    int numberOfSubstrings(string s) {
        int abc[3] = {-1, -1, -1};
        int count = 0;
        for (int right = 0; right < s.length(); ++right) {
            abc[s[right] - 'a'] = right;
            count += 1 + min({abc[0], abc[1], abc[2]});
        }
        return count;
    }
};
