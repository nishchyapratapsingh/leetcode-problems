#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlength = 1; 
        int n = nums.size();
        
        if (n == 1) return 1; 
        
        int inclength = 1, declength = 1; 
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) { 
                inclength++;      
                declength = 1;    
            } 
            else if (nums[i] < nums[i - 1]) { 
                declength++;      
                inclength = 1;   
            } 
            else {
                inclength = declength = 1; 
            }

            maxlength = max(maxlength, max(inclength, declength));
        }

        return maxlength;
    }
};
