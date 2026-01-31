class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> nge(n);

        for (int i = 2*n-1; i >= 0; i--) {
            while (!s.empty() && nums[i%(n)] >= s.top()) {
                s.pop();
            }

            if (!s.empty()) {
                nge[i%(n)] = s.top();
            }
            else nge[i%(n)] = -1;
            s.push(nums[i%(n)]);
        }

        return nge;
    }
};