class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        
        int total = 7 * (weeks * (weeks + 1) / 2) + 21 * weeks;
        
        total += days * (2 * (weeks + 1) + (days - 1)) / 2;
        
        return total;
    }
};
