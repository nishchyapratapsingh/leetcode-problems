class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> idxt;
        int i=0;
        for (char c: t) {
            idxt[c] = i;
            ++i;
        }
        int sum=0;
        for (int j=0; j<s.length(); ++j) {
            sum += abs(j - idxt[s[j]]);
        }
        return sum;
    }
};