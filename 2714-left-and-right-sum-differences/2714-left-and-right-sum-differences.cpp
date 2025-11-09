class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int tsum = 0;
        for (int num: nums) {
            tsum+=num;
        }
        int n = nums.size();
        vector<int> ans;
        int lsum=0; int rsum;
        for (int i=0; i<n; i++) {
            if (i>0) lsum+=nums[i-1];
            rsum = tsum-lsum-nums[i];
            ans.push_back(abs(lsum-rsum));
        }
        return ans;
    }
};