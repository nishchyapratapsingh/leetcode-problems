class Solution {

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> currPerm, vector<bool>& visited) {
        if (currPerm.size() == nums.size()) {
            result.push_back(currPerm);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            currPerm.push_back(nums[i]);
            backtrack(nums, result, currPerm, visited);
            currPerm.pop_back();
            visited[i] = false;
        }
        
       
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, result, {}, visited);
        return result;
    }
};