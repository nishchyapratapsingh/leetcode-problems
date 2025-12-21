class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size() - 1;
        while (i < n) {
            res.push_back((double)(nums[i] + nums[n]) / 2);
            i++;
            n--;
        }
        double mini = INT_MAX;
        for (double avg : res) {
            mini = min(avg, mini);
        }  
        return mini;
    }
};