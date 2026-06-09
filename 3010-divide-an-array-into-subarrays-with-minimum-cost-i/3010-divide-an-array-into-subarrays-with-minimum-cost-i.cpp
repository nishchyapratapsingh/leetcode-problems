class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX;
       
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                ans = min(ans, nums[0] + nums[i] + nums[j]);
            }
        }

        return ans;
    }
};