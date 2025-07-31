class Solution {
public:

    int atmost(vector<int>& nums, int goal) {
        int l=0;
        int sum=0;
        int ans=0;
        int n=nums.size();
        int r=0;
        while (r<n) {
            sum+=nums[r];

            while (sum>goal) {
                sum -= nums[l];
                l++;
            }

            ans += r-l+1;
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0){
            return atmost(nums, goal);
        }
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};