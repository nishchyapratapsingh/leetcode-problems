class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int currLowest=INT_MAX;
        int maxP=INT_MIN;
        for (int price: prices) {
            maxP = max(maxP, price - currLowest);
            currLowest = min(currLowest, price);
        }
        return maxP>0?maxP:0;
    }
};