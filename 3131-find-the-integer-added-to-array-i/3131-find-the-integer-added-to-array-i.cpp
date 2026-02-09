class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int totNum1 = 0;
        int totNum2 = 0;

        for (int num: nums1) {
            totNum1 += num;
        }

        for (int num: nums2) {
            totNum2 += num;
        }

        int diff = totNum2 - totNum1;
        
        int n = nums1.size();
        return diff/n;
    }
};