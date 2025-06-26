class Solution {

private:
    void backtrack(vector<int>& candidates, int target, int index, vector<vector<int>>& result,  vector<int> currss) {
        if (target==0) {
            result.push_back(currss);
            return;
        }

        if (target<0 || index == candidates.size()) {
            return;
        }

        currss.push_back(candidates[index]);
        backtrack(candidates, target-candidates[index], index, result, currss);
        currss.pop_back();

        backtrack(candidates, target, index+1, result, currss);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, result, {});
        return result;
    }
};