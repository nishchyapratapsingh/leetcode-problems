class Solution {
    bool solve(string &s, unordered_set<string>& dict, int start, unordered_set<int> &lengths, unordered_map<int, bool> &memo) {
        if (start == s.length()) {
            return true;
        }
        if (memo.count(start)) {
            return memo[start];
        }
        for (int len: lengths) {
            if (start+len <= s.length()) {
                string prefix = s.substr(start, len);
                if (dict.count(prefix) && solve(s, dict, start+len, lengths, memo)) {
                    return memo[start] = true;
                }
            }
        }
        return memo[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        unordered_set<int> lengths;
        for (string str: wordDict) {
            lengths.insert(str.length());
        }

        unordered_map<int, bool> memo;
        return solve(s, dict, 0, lengths, memo );
    }
};