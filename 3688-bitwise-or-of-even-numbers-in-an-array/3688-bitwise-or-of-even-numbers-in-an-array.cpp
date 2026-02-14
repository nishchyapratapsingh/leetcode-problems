class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n && nums[i]%2 != 0) {
            i++;
        }

        if (i == n) return 0;

        int ans = nums[i];
        i++;

        while (i < n) {
            if (nums[i] % 2 == 0) {
                ans = ans | nums[i];
            }
            i++;
        }

        return ans;
    }
};