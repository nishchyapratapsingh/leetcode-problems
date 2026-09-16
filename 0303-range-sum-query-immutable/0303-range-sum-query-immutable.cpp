class NumArray {
    vector<int> ps;
public:
    NumArray(vector<int>& nums) {
        ps.resize(nums.size()+1);
        ps[0] = 0;

        for (int i = 1; i < nums.size()+1; i++) {
            ps[i] = ps[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return ps[right+1] - ps[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */