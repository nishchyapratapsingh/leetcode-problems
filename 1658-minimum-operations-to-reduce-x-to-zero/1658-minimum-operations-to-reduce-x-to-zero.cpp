class Solution {
    int maxSumK(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = -1;
        int sum = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l <= r && sum > k) {
                sum -= nums[l];
                l++;
            }

            if (sum == k) ans = max(ans, r-l+1);
        }

        return ans;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        //maximum length subarray with sum total - x
        int t = 0;
        int n = nums.size();
        for (int num : nums) {
            t += num;
        }

        int len = maxSumK(nums, t-x);

        return len == -1 ? -1 : n - len;
    }
};