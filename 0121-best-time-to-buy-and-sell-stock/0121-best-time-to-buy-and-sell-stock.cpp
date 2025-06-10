class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        int n=prices.size();
        for (int i=0; i<n; i++) {
            minprice = min(minprice, prices[i]);
            maxprofit = max(prices[i]-minprice, maxprofit);
        }  
        return maxprofit;  
    }
};