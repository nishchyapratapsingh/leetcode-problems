class Solution {
public:

    int recursiveSearch(vector<int> &nums, int s, int e, int target) {
        int m = s+ (e-s)/2;

        if (s>e) {
            return -1;
        }

        if (nums[m]==target) {
            return m;
        }

        else if (nums[m]>target) {
            return recursiveSearch(nums, s, m-1, target);
        }

        else {
            return recursiveSearch(nums, m+1, e, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return recursiveSearch(nums, 0, nums.size()-1, target);
    }
};