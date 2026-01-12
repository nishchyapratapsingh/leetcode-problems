class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> p(n+1);
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i-1] + arr[i-1];
        }
        int sum = p[n];
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j<n; j++) {
                if ((j-i+1)%2!=0) {
                    sum+=p[j+1]-p[i];
                }
            }
        }
        return sum;
    }
};