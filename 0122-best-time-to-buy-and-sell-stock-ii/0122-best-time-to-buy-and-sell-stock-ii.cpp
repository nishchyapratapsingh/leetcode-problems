class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevPrice = prices[0];
        int totalProfit = 0;
        for (int price: prices) {
            if (price>prevPrice)
            totalProfit += (price - prevPrice);
            prevPrice = price;
        }
        return totalProfit;
    }
};