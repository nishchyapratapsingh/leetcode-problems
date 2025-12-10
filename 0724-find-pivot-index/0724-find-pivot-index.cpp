class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i=1; i<n; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for (int i=0; i<n; i++) {
            int lSum = i==0?0:prefix[i-1];
            int rSum = prefix[n-1] - prefix[i];
            if (lSum-rSum==0) return i;
        }
        return -1;
    }
};