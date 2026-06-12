class Solution {
private:
    void f(int i, bool prev, int n, string &cur, vector<string> &ans) {
        if (i == n) {
            ans.push_back(cur);
            return;
        }

        if (prev) {
            cur.push_back('1');
            f(i+1, 0, n, cur, ans);
            cur.pop_back();
        }

        else {
            cur.push_back('0');
            f(i+1, 1, n, cur, ans);
            cur.pop_back();
            cur.push_back('1');
            f(i+1, 0, n, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string cur;
        f(0, 0, n, cur, ans);

        return ans;
    }
};