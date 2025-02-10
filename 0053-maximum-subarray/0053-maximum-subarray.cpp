class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //we can use Kadane's algorithm

        int currsum = nums[0];
        int maxsum = nums[0];

        for (int i=1; i<nums.size(); i++) {

            currsum = max(nums[i], currsum + nums[i]);
            maxsum = max(maxsum, currsum);

        }

        return maxsum;
        
    }
};