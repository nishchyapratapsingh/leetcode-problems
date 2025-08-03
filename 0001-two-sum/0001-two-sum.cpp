class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int> map;
        for (int i=0; i<n; ++i) {
            if (map.count(nums[i])) {
                return {map[nums[i]], i};
            }
            map[target-nums[i]]=i;
        }
        return {};
    }
};