class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        int count = 0;
        int n = nums.size();

        // Iterate over all subsets
        for (int mask = 0; mask < (1 << n); ++mask) {
            int currOr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currOr |= nums[i];
                }
            }
            if (currOr == maxOr) {
                ++count;
            }
        }
        return count;
    }
};
