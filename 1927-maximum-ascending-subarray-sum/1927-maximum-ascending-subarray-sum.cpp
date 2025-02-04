class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        long long maxsum = 0;

        int i=1; 
        while (i<n) {
            long long sum = nums[i-1];
            int j=i;
            while (j<n && nums[j] > nums[j-1]) {
                sum += nums[j];
                j++;
            }

            maxsum = max(sum, maxsum);
            i++;
        }

        return maxsum;
    }
};