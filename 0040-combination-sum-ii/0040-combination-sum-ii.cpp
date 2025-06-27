class Solution {

    void backtrack(vector<int>& candidates, int target, int index, vector<vector<int>>& result, vector<int> currvec) {
        if (target == 0) {
            result.push_back(currvec);
            return;
        }
       

        for (int i=index; i<candidates.size(); i++) {
            if (index<i && candidates[i]==candidates[i-1]) continue;
            if (candidates[i]>target) break;

            currvec.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1,result, currvec );
            currvec.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        backtrack(candidates, target,0, result, {});
        return result;
    }
};