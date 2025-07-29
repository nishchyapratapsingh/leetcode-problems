class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> rightMost(32, -1); 

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if (nums[i] & (1 << bit)) {
                    rightMost[bit] = i;
                }
            }
            int furthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (rightMost[bit] != -1) {
                    furthest = max(furthest, rightMost[bit]);
                }
            }
            ans[i] = furthest - i + 1;
        }
        return ans;
    }
};
