class Solution {
public:
    void helper(set<vector<int>>& result, vector<int>& nums, int index, vector<int> currsubs) {
        if (index == nums.size()) {
            result.insert(currsubs);
            return;
        }

        currsubs.push_back(nums[index]);
        helper(result, nums, index+1, currsubs);
        currsubs.pop_back();
        helper(result, nums, index+1, currsubs);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dupCheck;
        set<vector<int>> result;
        helper(result, nums, 0, {});
        return vector<vector<int>>(result.begin(), result.end());
    }
};