class Solution {
    int findSetBits(int idx) {
        int cnt = 0;
        while (idx) {
            if (idx%2 == 1) cnt++;
            idx/=2;
        }
        return cnt;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            if(k == findSetBits(i)) {
                sum += nums[i];
            }
        }
        return sum;
    }
};