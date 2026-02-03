class Solution {
    void backtrack(string &num, int target, string curr, vector<string> &ans, int idx, long long eval, long long prevVal) {
        if (idx == num.length()) {
            if (eval == target) {
                ans.push_back(curr);
            }

            return;
        } 

        for (int i = idx; i < num.length(); i++) {
            if (i != idx && num[idx] == '0') break;
            
            string part = num.substr(idx, i - idx + 1);
            long long exp = stoll(part);

            if (idx == 0) {
                backtrack(num, target, curr+part, ans, i+1, exp, exp);
            }

            else {
                backtrack(num, target, curr+'+'+part, ans, i+1, eval+exp, exp);
                backtrack(num, target, curr+'-'+part, ans, i+1, eval-exp, -exp);
                backtrack(num, target, curr+'*'+part, ans, i+1, (eval-prevVal) + prevVal*exp, prevVal*exp);


            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        backtrack(num, target, "", ans, 0, 0, 0);

        return ans;
    }
};