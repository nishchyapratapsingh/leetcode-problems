class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int n = apple.size();
        int m = capacity.size();

        int j = 0;
        int cur = capacity[j];
        for (int i = 0; i < n; i++) {
            while (cur < apple[i] && j+1 < m) {
                cur += capacity[++j];
            }
            cur -= apple[i];
        }

        return j+1;
    }
};