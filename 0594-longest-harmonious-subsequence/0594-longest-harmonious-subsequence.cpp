class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans=0;
        for (int num:nums) {
            freq[num]++;
        }
        for (auto &[num, count]: freq) {
            if (freq.count(num+1)) {
                ans = max(ans, count+freq[num+1]);
            }
        }
        return ans;
    }
};