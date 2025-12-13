class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int cnt=0;
        for (int i=0; i<n; i++) {
            while (i<n-1 && nums[i+1]==nums[i]) {
                continue;
            } 
            int j=i+1;
            int k=n-1;
            while(j<k) {
                while (j<k-1 && nums[j+1]==nums[j]) {
                    j++;
                }
                while (j+1<k && nums[k-1]==nums[k]) {
                    k--;
                }
                if(nums[j]-nums[i]<diff) j++;
                else if (nums[j]-nums[i]>diff) break;
                else {
                    if (nums[k]-nums[j]>diff) k--;
                    else if (nums[k]-nums[j]<diff) break;
                    else {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};