class Solution {
    bool f(string &s, string &word) {
        int n = s.length();
        int m = word.length();
        for (int i = 0; i <= m-n; i++) {
            if (word.substr(i, n) == s) return true;
        }

        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (string s : patterns) {
            if (f(s, word)) {
                cnt++;
            }
        }

       return cnt; 
    }
};