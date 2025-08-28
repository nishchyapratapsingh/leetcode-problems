class Solution {
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1;
        int k=m+n-1;
        while (i>=0 && j>=0) {
            if (nums1[i]>nums2[j]) {
                nums1[k--]=nums1[i--];
            }
            else {
                nums1[k--]=nums2[j--];
            }
            
        }
        while (j>=0) {
            nums1[k--]=nums2[j--];
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); int n=nums2.size();
        vector<int> nums3(m+n);
        for (int i=0; i<m; i++) {
            nums3[i]=nums1[i];
        }
        merge(nums3, nums1.size(), nums2, nums2.size());
        if ((m+n)%2==0) {
            return (double)(nums3[(m+n)/2] + nums3[(m+n)/2 - 1])/2;
        }
        else return (double)nums3[(m+n)/2];
        return nums3[(m+n)/2];
    }
};