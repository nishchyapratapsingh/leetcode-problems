class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<bool> flip(n, false);
        int zeros = 0;
        int l=0;
        int maxOne = 0;
        int nFlips=0;

        for (int r=0; r<n; r++) {
            if (nums[r]==0) {
                zeros++;
                nFlips++;
            }
            while (nFlips>k) {
                if(nums[l]==0) {nFlips--; zeros--;};
                l++;
            }
            maxOne = max(maxOne, r-l+1);
        }
        return maxOne;
    }
};