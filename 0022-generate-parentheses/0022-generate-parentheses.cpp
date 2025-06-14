class Solution {
public:
    void solve(int open, int close, int n, string &temp, vector<string> &result) {
        if (close==n) {
            result.push_back(temp);
            return;
        } 
        

        if (open<n) {
            temp.push_back('(');
            solve(open+1, close, n, temp, result);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(open, close+1, n,temp, result);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        solve(0, 0,n, temp ,result);
        return result;
    }
};