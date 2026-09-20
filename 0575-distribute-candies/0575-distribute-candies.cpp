class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        int n = candyType.size();

        for (int candy : candyType) {
            s.insert(candy);
        }
        
        int sze = s.size();
        return min(n/2,sze);
    }
};