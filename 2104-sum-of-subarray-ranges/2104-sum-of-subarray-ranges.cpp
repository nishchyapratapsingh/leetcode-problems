class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
		long long sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
        	long long mini = nums[i];
        	long long maxi = mini;
        	for (int j = i; j < n; j++) {
        		mini = min((long long)nums[j], mini);
        		maxi = max((long long)nums[j], maxi);

        		sum = sum + maxi - mini;
        	}
        }

        return sum;
    }
};