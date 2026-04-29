class Solution {
public:
    std::vector<int> minCosts(std::vector<int>& cost) {
        std::vector<int> result(cost.size());
        std::partial_sum(cost.begin(), cost.end(), result.begin(), [](int a, int b) {
            return std::min(a, b);
        });
        return result;}
};