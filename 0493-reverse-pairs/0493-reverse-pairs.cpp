class Solution {
public:
    void merge(vector<int> &nums, int s, int m, int e) {
        vector<int> temp;
        int left = s;
        int right = m+1;
        
        while(left<=m && right <= e) {
            if (nums[left]>nums[right]) {
                temp.push_back(nums[right++]);
            }
            else {
                temp.push_back(nums[left++]);
            }
        }
        while (left<=m) {
            temp.push_back(nums[left++]);
        }
        while (right<=e) {
            temp.push_back(nums[right++]);
        }

        for (int i=s; i<=e; i++) {
            nums[i] = temp[i-s];
        }
    }

    int cntPairs(vector<int> &nums, int s, int m , int e) {
        int cnt = 0;
        int left = s;
        int right = m+1;

        while (left<=m && right<=e) {
            if (nums[left]>2*1LL*nums[right]) {
                cnt+=m-left+1;
                right++;
            }
            else
            left++;
        }

        return cnt;
    }

    int mergeSort(vector<int> & nums, int left , int right) {
        int cnt=0;

        if (left>=right) {
            return 0;
        }

        int mid = left+(right-left)/2;

        cnt += mergeSort(nums, left, mid);
        cnt += mergeSort(nums, mid+1, right);
        cnt += cntPairs(nums, left, mid, right);
        merge(nums, left, mid, right);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int cnt;
        cnt = mergeSort(nums, 0, nums.size()-1);
        return cnt; 
    }
};