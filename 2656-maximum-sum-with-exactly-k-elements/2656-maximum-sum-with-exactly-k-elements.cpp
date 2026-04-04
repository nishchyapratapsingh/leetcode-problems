class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = nums[0];
        for (int num: nums) {
            mx = max(mx, num);
        }
        int val = 0;
        for (int i = 0; i < k; i++) {
            val+=mx++;
        }

        return val;
    }
};