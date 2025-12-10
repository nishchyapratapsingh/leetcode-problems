class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int totalSum=0;
        for (int i=0; i<nums.size(); ++i) {
            int currSum=0;
            currSum+=nums[i];
            int start = max(0, i - nums[i]);
            for (int j=start; j<i; j++) {
                currSum+=nums[j];
            }
            totalSum+=currSum;
        }
        return totalSum;
    }
};