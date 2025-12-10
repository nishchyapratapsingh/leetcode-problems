class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tSum=0;
        for (int num: nums) {
            tSum+=num;
        }
        int lSum=0;
        for (int i=0; i<nums.size(); i++) {
            int rSum = tSum-nums[i]-lSum;
            if (lSum-rSum==0) return i;
            lSum+=nums[i];
        }
        return -1;
    }
};