class Solution {
public:

    int atmost(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int sum=0;
        int ans=0;

        for (int r=0; r<n; ++r) {
            if (nums[r]%2!=0) {
                sum++;
            }
            while (sum>k) {
                if (nums[l]%2!=0) {
                    sum--;
                }
                l++;
            }
            ans=ans+r-l+1;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};