class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n+1);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1]+nums[i-1];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (ps[j] - ps[i] == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};