class Solution {

    void backtrack(vector<int> nums, vector<vector<int>>& result, int index) {
        if (index>=nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j=index; j<nums.size(); j++) {
            swap(nums[j], nums[index]);
            backtrack(nums, result, index+1);
            swap(nums[j], nums[index]);
        }
       
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};