class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int currSum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (m.find(currSum-k) != m.end()) {
                cnt+=m[currSum-k];
            }
            m[currSum]++;
        }
        return cnt;
    }
};