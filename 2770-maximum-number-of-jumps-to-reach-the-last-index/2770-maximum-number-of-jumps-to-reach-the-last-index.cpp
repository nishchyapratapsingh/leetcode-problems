class Solution {
private:
    int f(int i, vector<int> &t,vector<int> &nums, int target) {
        if (i == nums.size()-1) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int ans = INT_MIN;
        for (int j = i+1; j < nums.size(); j++) {
            if (abs(nums[i]-nums[j]) <= target) {
                int next = f(j, t, nums, target);
                if (next != INT_MIN) ans = max(ans, next+1);
            }
        }

        return t[i] = ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> t(nums.size(), -1);
        int ans = f(0, t, nums, target);
        return ans == INT_MIN ? -1 : ans;
    }
};