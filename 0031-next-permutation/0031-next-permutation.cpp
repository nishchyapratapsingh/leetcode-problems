class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for (int j=n-1; j>0; j--) {
            if (nums[j-1]<nums[j]) {
                int i=j;
                    while (i<n && nums[i]>nums[j-1]) {
                        i++;
                    }
                    swap(nums[j-1], nums[i-1]);
                reverse(nums.begin() + j, nums.end());    
                return;        
                }
        }
        reverse(nums.begin(), nums.end()); //when array is in descending order
    }
};