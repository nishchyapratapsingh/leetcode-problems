class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for (int num: gain) {
            sum+=num;
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};