class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        while (i<n&&j<m) {
            if (nums1[i]==nums2[j]) {
                ans.push_back(nums1[i]);
                int val=nums1[i];
                while(i<n && nums1[i]==val) {
                    i++;
                }
                while(j<m && nums2[j]==val) {
                    j++;
                }
            }
            else if (nums1[i]<nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};