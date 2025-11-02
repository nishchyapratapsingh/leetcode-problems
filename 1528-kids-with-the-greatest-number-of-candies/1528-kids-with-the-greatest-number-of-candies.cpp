class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        for (int candy: candies) {
            maxi = max(candy, maxi);
        }
        vector<bool> res(candies.size());
        for (int i=0; i<candies.size(); i++) {
            res[i] = (candies[i]+extraCandies )>= maxi ? true: false;
        }
        return res;        
    }
};