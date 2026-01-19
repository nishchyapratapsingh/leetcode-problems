class Solution {
    unordered_map<int, bool> memo;
    bool solve(string &s, unordered_set<string>& dict, int start) {
        if (start == s.length()) {
            return true;
        }
        if (memo.count(start)) {
            return memo[start];
        }
        for (int end = start+1; end <= s.length(); end++) {
            string prefix = s.substr(start, end-start);
            if (dict.count(prefix) && solve(s, dict, end)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> memo(s.length(), -1);
        return solve(s, dict, 0);
    }
};