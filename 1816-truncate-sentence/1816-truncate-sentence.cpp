class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int cnt=0;
        for (char c: s) {
            if (c==' ') cnt++;
            if (cnt == k) return res;
            res.push_back(c);
        }
        return res;
    }
};