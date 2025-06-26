class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> currsum, int index) {
        result.push_back(currsum);
        for (int i=index; i<nums.size(); i++) {
            if (i>index && nums[i]==nums[i-1]) continue;
            currsum.push_back(nums[i]);
            backtrack(nums, result, currsum, i+1);
            currsum.pop_back();            
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        backtrack(nums, result, {}, 0);
        return result;
    }
};