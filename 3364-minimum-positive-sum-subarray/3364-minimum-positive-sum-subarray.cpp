class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r) {
                    if (cur > 0) ans = min(cur, ans);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;


    }
};