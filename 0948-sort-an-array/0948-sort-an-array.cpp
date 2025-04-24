class Solution {
public:

    void merge(vector<int>& nums, int s, int m, int e, vector<int>& temp) {
        int left = s;
        int tempIdx = s;
        int right = m+1;
        while (left<=m && right <=e) {
            if (nums[left]<nums[right]) {
                temp[tempIdx++]=nums[left++];
            }
            else {
                temp[tempIdx++]=nums[right++];
            }
        }

        while (left<=m) {
            temp[tempIdx++]=(nums[left++]);
        }

        while (right<=e) {
            temp[tempIdx++]=(nums[right++]);
        }

        for (int i=s; i<=e; i++) {
            nums[i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e, vector<int>& temp) {
        if (s>=e) {
            return;
        }
        int m=s+(e-s)/2;
        mergeSort(nums, s, m, temp);
        mergeSort(nums, m+1, e, temp);
        merge(nums, s, m ,e, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, 0, nums.size()-1, temp);

        return nums;
    }
};