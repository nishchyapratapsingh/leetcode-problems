class Solution {
private:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(int num, int sum, int k, int n) {
        if (sum == n && cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        if (sum > n || cur.size() > k)
        return;

        for (int i = num; i <= 9; i++) {
            cur.push_back(i);
            backtrack(i+1, sum+i, k, n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, 0, k, n);
        return ans;
    }
};