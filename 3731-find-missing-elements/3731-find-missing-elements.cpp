class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        for (int num : nums) {
            mini = min(num, mini);
            maxi = max(num, maxi);
        }

        vector<int> ans;
        
        vector<bool> exist(maxi-mini+1);

        for (int num: nums) {
            exist[num-mini] = true;
        }

        for (int i = 1; i < exist.size(); i++) {
            if (!exist[i]) ans.push_back(i+mini);
        }

        return ans;
    }
};