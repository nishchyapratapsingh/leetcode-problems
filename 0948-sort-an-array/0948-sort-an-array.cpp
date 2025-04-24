class Solution {
public:

    void merge(vector<int>& nums, int s, int m, int e) {
        int left = s;
        int right = m+1;
        vector<int> temp;

        while (left<=m && right <=e) {
            if (nums[left]<nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
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

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s>=e) {
            return;
        }
        int m=s+(e-s)/2;
        mergeSort(nums, s, m);
        mergeSort(nums, m+1, e);
        merge(nums, s, m ,e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};