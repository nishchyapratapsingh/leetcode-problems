class Solution {
public:

    void solve(vector<int> nums, vector<int> output,vector<vector<int>> &result, int index) {
        //base case
        if (index>=nums.size()) {
            result.push_back(output);
            return;
        }

        //exclude
        solve(nums, output, result, index+1);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, result, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        int index=0;
        solve(nums, output, result, index);
        return result;
    }
};