class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> flip(n, false);
        int l=0;
        int maxOne = 0;
        int nFlips=0;

        for (int r=0; r<n; r++) {
            if (nums[r]==0) {
                flip[r]=true;
                nFlips++;
                nums[r]=1;
            }
            while (nFlips>k) {
                if(flip[l]) nFlips--;
                l++;
            }
            maxOne = max(maxOne, r-l+1);
        }
        return maxOne;
    }
};