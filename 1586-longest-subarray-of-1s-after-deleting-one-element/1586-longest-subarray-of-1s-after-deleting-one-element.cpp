class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0; int r=0; int zeros=0; int maxi=0;
        while (r<n) {
            if (nums[r]==0) zeros++;
            while (l<r && zeros>1) {
                if (nums[l]==0) zeros--;
                l++;
            }
            maxi = max(r-l, maxi);
            r++;
        }
        return maxi;
    }
};