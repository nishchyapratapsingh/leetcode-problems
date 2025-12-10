class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for (int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int totalSum = 0;
        for (int i=0; i<n; ++i) {
            int currentSum;
            int start = max(0, i - nums[i]);
            if (start == 0) {
                currentSum = prefix[i];
            }
            else {
                currentSum = prefix[i] - prefix[start-1];
            }
            totalSum += currentSum;
        }
        return totalSum;
    }
};