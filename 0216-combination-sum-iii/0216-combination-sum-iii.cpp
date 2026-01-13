class Solution {
    void solve(int num, int k, int target, vector<vector<int>> &res, vector<int> &curr) {
        if (target == 0 && curr.size() == k) {
            res.push_back(curr);
            return;
        }
        if (curr.size() > k || num == 10) {
            return;
        }
        for (int i = num; i < 10; i++) {
            curr.push_back(i);
            solve(i+1, k, target-i, res, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(1, k, n, res, curr);
        return res;
    }
};