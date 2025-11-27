class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        for (int n:nums) {
            if (n<k) cnt++;
        }
        return cnt;
    }
};