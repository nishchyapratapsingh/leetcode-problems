class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalXor = 0;
        for (int x : nums)
            totalXor |= x;       
        return totalXor * (1 << (nums.size() - 1));
    }
};
