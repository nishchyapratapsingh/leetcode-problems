class Solution {
    int solve(vector<int> & nums, int k) {
        int n=nums.size();
        int distinct = 0;
        unordered_map<int, int> freqMap;
        int l=0;
        int count=0;

        for (int r=0; r<n; r++) {
            if (freqMap[nums[r]]==0) distinct++;
            freqMap[nums[r]]++;

            while (distinct>k) {
                freqMap[nums[l]]--;
                if (freqMap[nums[l]]==0) distinct--;
                l++;
            }

            count+=r-l+1;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};