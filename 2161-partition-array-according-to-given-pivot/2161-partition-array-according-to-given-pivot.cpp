class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> arr;

        for (int num: nums) {
            if (num < pivot) {
                arr.push_back(num);
            }
        }
        for (int num: nums) {
            if (num == pivot) {
                arr.push_back(num);
            }
        }
        for (int num: nums) {
            if (num > pivot) {
                arr.push_back(num);
            }
        }

        return arr;
    }
};