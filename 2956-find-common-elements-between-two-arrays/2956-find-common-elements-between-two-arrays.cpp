class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        bool in2[101] = {};
        bool in1[101] = {};
        for (int x : nums2) in2[x] = true;
        for (int x : nums1) in1[x] = true;
        
        int count1 = 0, count2 = 0;
        for (int x : nums1)
            if (in2[x]) count1++;
        for (int x : nums2)
            if (in1[x]) count2++;
        
        return {count1, count2};
    }
};
