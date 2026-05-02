class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int F = 0;
        int maxi;
        int tsum = 0;
        
        for (int k = 0; k < n; k++) {
            F += k*nums[k];
            tsum += nums[k];
        }

        maxi = F;
        int toRemove; 

        for (int i = 1; i < n; i++) {
            toRemove = nums[n-i] * (n-1);
            // F = F - (nums[n-i] * (n-1)) + tsum - nums[n-i];
            F = F + tsum - n * nums[n-i];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};