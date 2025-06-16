class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxDiff = INT_MIN;
        int minElem = INT_MAX;
        for (int i=0; i<n; i++) {
            minElem = min(minElem, nums[i]);
            maxDiff = max(maxDiff, nums[i]-minElem);
        }
        return (maxDiff<=0)?-1:maxDiff;
    }
};