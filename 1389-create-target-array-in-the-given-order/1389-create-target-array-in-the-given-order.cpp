class Solution {
    void addVal(vector<int>& target, int val, int idx, int n, int filled) {
        for (int i = filled; i > idx; i--) {
            target[i] = target[i - 1];
        }
        target[idx] = val;
    }

public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target(n);
        int filled = 0;

        for (int i = 0; i < n; i++) {
            addVal(target, nums[i], index[i], n, filled);
            filled++;
        }
        return target;
    }
};
