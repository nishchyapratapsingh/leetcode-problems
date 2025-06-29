class Solution {

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<bool>& visited, vector<int> currPerm) {
        if (currPerm.size()==nums.size()) {
            result.push_back(currPerm);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (visited[i]) continue;
            if (i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = true;
            currPerm.push_back(nums[i]);
            backtrack(nums, result, visited, currPerm);
            currPerm.pop_back();
            visited[i]=false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, result, visited, {});
        return result;
    }
};