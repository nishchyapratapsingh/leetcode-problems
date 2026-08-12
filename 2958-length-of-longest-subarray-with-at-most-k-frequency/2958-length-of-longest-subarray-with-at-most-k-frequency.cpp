class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int mx = 0;

        for (int r = 0; r < n; r++) {   
            freq[nums[r]]++;

            while (l <= r && freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }

            mx = max(mx, r-l+1);
        }

        return mx;
    }
};